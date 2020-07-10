#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        string key;
        int val;
        Node(string key, int val)
        {
            this->key = key;
            this->val = val;
        }
};
class HashTable
{
    public: 
    int n = 4;
    vector<list<Node*>>buckets;
    int sizee = 0;
    HashTable()
    {
        buckets.resize(4);
        //int sizee =  0;
    }
    int size()
    {
        return sizee;
    }
    int hashfunc( string key)
    {
        int hash_idx = 0;
        int p = 1;
        for(int i = 0 ; i < key.length() ; i++)
        {
            hash_idx += key[i]*( p % buckets.size() );
            p = p * 37;
        }
        hash_idx = hash_idx % buckets.size(); 
        return hash_idx;
    }

    void insert( string key , int val)
    {
        int hash_idx = hashfunc(key);
        buckets[hash_idx].push_back(new Node( key , val));
        sizee++;

        float load_factor = size()/n;      //current size / total size
        if( load_factor > 2.0)
        {            
            sizee = 0;
            rehash();
        }
    }
    void rehash()
    {
        vector<list<Node*>>oldbuckets = buckets;
        int old_n = n;
        n = n * 2;
        //sizee = 0;
        
        for(int i = 0 ; i < buckets.size() ; i++) buckets[i].clear();  // clear all linkedlist
        buckets.resize( n );
        for(auto l : oldbuckets)
        {
            for(Node* node : l)
            {
                insert( node -> key , node -> val);
            }
        }
    }
    void get( string key)
    {
        int i = hashfunc( key );

        list<Node*>curr = buckets[i];
        for(Node * n : curr)
        {
            if(key == n->key)
            {
                cout << n -> val;
                break;  
            } 
        }
    }
    bool containsKey( string key)
    {
        int i = hashfunc( key );

        for(Node* n : buckets[i])
        {
            if( key == n->key) return true; 
        }
        return false;
    }
    int removee( string key)
    {
        int i = hashfunc( key ); 
        list<Node*>:: iterator it;
        for(it = buckets[i].begin() ; it != buckets[i].end() ; it++)
        {   
            if( (*it)->key == key)
            {   
                int v = (*it) -> val;
                buckets[i].erase(it);
                sizee--;                
                return v;
            }
        }
        return -1;
    }
    vector<string>keyset()
    {
        vector<string>keys;
        for(auto l : buckets)
        {
            for(Node * n : l) keys.push_back(n->key);
        }
        return keys;
    }
    void display()
    {
        cout << "Display Begins" << endl;
        for(int i = 0 ; i < buckets.size() ; i++)
        {
            cout << "Bucket" << i << " ";
            for(Node* node : buckets[i]) cout << node -> key << "@" << node -> val << " ";
            cout << "." << endl;
        }
    }
};
int main()
{   
    HashTable *map = new HashTable();
    // map->insert("joe" , 100);
    // map->insert("jorn" , 200);
    // map->insert("rrse" , 300);
    // map->insert("joae" , 100);
    // map->insert("jofgrn" , 200);
    // map->insert("rrwe" , 300);

    //cout << map->buckets.size();   //BUCKET SIZE
    //map->display();   //DIsplay
    //map->get( "rre" );

    // if( map->containsKey( "rrew")) cout <<" true";
    // else cout << " false";
    //cout << map->hashfunc(" joe");
    
    //cout << map->removee( "rre") << endl;

    // vector<string>keysett = map->keyset();
    // for(auto s : keysett) cout << s << " ";

    //map->display();
    //cout << map->size();

    // string str , str;
    // getline( cin , str);  


    // while( str != "quit")
    // {   
    //     char * spl = strtok(str, " "); 
    //     else if ( spl[0] == "put")
    //     {   
    //         // getline(X , str , ' '); string key = str ; 
    //         // getline( X , str , ' '); int val = stoi( str ); 
    //         map -> insert( spl[1] , stoi(spl[2]) );
    //     }
    //     else if ( spl[0] == "get") {
    //     //getline(X , str , ' '); 
    //     string key = spl[1];
    //     map -> get( key ); cout << endl;
    //     }
    //     else if ( spl[0] == "containsKey") {
    //     //getline(X , str , ' ');
    //      string key = spl[1];
    //     cout << map -> containsKey( key ) << endl;
    //     }
    //    else if ( spl[0] == "remove") {
    //     //getline(X , str , ' ');
    //      string key = spl[1];
    //     cout << map -> removee(key) << endl;
    //     }
    //    else if (spl[0] == "size") {
    //     cout << map->size() << endl;
    //    }
    //    else if (spl[0] == "keyset"){
    //     vector<string> keyy = map -> keyset();
    //     for( string s : keyy ) cout << s << " ";
    //     }
    //    else if (spl[0] == "display")
    //     {
    //         map->display();
    //     }
    //    getline( cin , str);
    //    //stringstream X(str);
    //    //getline( X ,str , ' ');
    // }
    

    // stringstream X( str );

    // getline( X ,str , ' ');  
    string str ;
    cin >> str; 
    while( str != "quit" )
    {   
        if( str == "quit") break;
        else if ( str == "put")
        {   
            string key ; cin >> key;
            int val; cin >> val;
            map -> insert( key , val ) ;
        }
        else if ( str == "get") {
        string key ; cin >> key;
        map -> get( key ); cout << endl;
        }
        else if ( str == "containsKey") {
        string key ; cin >> key;
        cout << map -> containsKey( key ) << endl;
        }
        else if ( str == "remove") {
        string key; cin >> key;
        cout << map -> removee(key) << endl;
        }
       else if (str == "size") {
        cout << map->size() << endl;
       }
       else if (str == "keyset"){
        vector<string> keyy = map -> keyset();
        for( string s : keyy ) cout << s << " ";
        }
       else if (str == "display")
        {
            map->display();
        }
        string temp ; cin >> temp;
        str = temp;
    }
    
   // map->display();

    return 0;
}   
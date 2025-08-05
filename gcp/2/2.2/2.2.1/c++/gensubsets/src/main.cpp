#include <iostream>
#include <vector>

using namespace std;

vector<int> subset; 

void search( int k, vector<int>& subset, const int n ) {
    if ( k == n+1 ) {
        for ( auto s : subset ) { printf( "%d ", s ); }
        printf( "\n" );

    }
    else {
        subset.push_back(k);
        search( k+1, subset, n );   // {k, subset{}] {2, { 1 }} ; { 3, { 1, 2 }}, { 4, { 1, 2, 3 }}
        printf( "k: %d\n", k );
        subset.pop_back();
        search( k+1, subset, n );
    }
}

void search( int k, const int n ) {
    if ( k == n+1 ) {
        for ( auto s : subset ) { printf( "%d ", s ); }
        printf( "\n" );

    }
    else {
        subset.push_back(k);
        search( k+1, n );   // {k, subset{}] {2, { 1 }} ; { 3, { 1, 2 }}, { 4, { 1, 2, 3 }}
        printf( "k: %d\n", k );
        subset.pop_back();
        search( k+1, n );
    }
}

int main() {
    const int n = 3;

    std::cout << "gensubsets global:" << std::endl;

    search( 1, n );

    std::cout << "gensubsets reference:" << std::endl;
    {
        vector<int> subset; 
        search( 1, subset, n );
    }
    
    return 0;
}

/*
search(1, 3)
    push_back(k=1, {1})
    search(k=2)
        push_back(k=2, {1, 2})
        search(k=2)
            push_back(k=3, {1, 2, 3})
            search(k=4)
                =>print {1, 2, 3 }
        
            
            

*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string> 
#include <vector>
#include <map>
#include <set>
#include <queue>  
#include <stack> 
#include <limits.h> 

using namespace std;

class Graph{

    int n,m;

    vector< pair<int,int> >*g;

    vector<int>distance;///distance from the source node...

    set<pair<int,int>>dist_min_set;

    vector<bool>mark;

    public:

        Graph(int n,int m){

            g = new vector< pair<int,int> >[n+1];

            this -> n = n;

            this -> m = m;

        }

        void insert_node(int u,int v,int weight){

            g[u].push_back( make_pair(v,weight) );

            g[v].push_back( make_pair(u,weight) );

        }

        void display(){

            for(int i=0;i<n; i++){

                if(g[i].size()){

                    cout << i << "--> ";

                    for(auto it = g[i].begin();it != g[i].end();it++){

                        cout <<"("<< it ->first  << " , "<<it->second<<" ), ";

                    }

                    cout << "\n";

                }

            }

        }



        int dijkstra(int source){



            //fill_n(mark.begin(),n+1,false);

            for(int i=0;i<n;i++)

                mark.push_back(false);

            for(int i=0;i<m;i++){

                distance.push_back(INT_MAX);

            }



            distance[source] = 0;

            dist_min_set.insert(make_pair(0,source));



            while(!dist_min_set.empty()){



                auto p = dist_min_set.begin();

                dist_min_set.erase(dist_min_set.begin());



                int parent = p->second;

                mark[parent] = true;

                for(auto it = g[parent].begin(); it != g[parent].end(); it++){



                    int child = it -> first;

                    int weight = it ->second;



                    if(distance[child] > distance[parent] + weight && mark[child]==false){



                        if(distance[child] != INT_MAX){

                            dist_min_set.erase(dist_min_set.find(make_pair(distance[child],child)));

                        }



                        distance[child] = weight  + distance[parent];

                        dist_min_set.insert(make_pair(distance[child],child));

                    }

                }

            }


             int min = 1e9;
            for(int i=0;i<n;i++){
             if(distance[i]!=0 &&  distance[i]<min)
             min = distance[i];

            }
           return min;
        }

};

int main(){



    int n,m,u,v,weight;

    cin >> n;


    cin >> m;

    Graph g(n,m);

    for(int i = 0;i < m;i++){

        cin >> u >> v >> weight;

        g.insert_node(u-1,v-1,weight);

        cout << "\n";

    }

    g.display();


    int source = 0;
    int minn = 1e9;
for(int i=0; i<n; i++){
    int mm = g.dijkstra(i);
    if(mm<minn && mm!=0)
        minn = mm;

}
cout << minn << endl;

}

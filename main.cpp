//
// Created by Ashton Hess on 2/19/22.
//
#include <iostream>
#include <vector>
#include<queue>
#include<string>
#include<fstream>

using namespace std;

int**readInAdjMatrix(string fileName, int&n);
void printAdjMatrix(int**adjMatrix, int n);

typedef struct Node{
    int val;
    int state;
}node;

//void addEdge(int x, int y, vector<vector<int> > adj){
//    adj[x][y]=1;
//    adj[y][x]=1;
//}



int main(int argc, char*argv[]){


    string filename;
    int sourceNode;
    int n;

    cout << "Number of arguments entered: " << argc << endl;
    for (int i=0;i<argc;i++){
        cout << "Argument "<< i << ": " << argv[i] << endl;
    }
    if (argc == 3){
        //if correct amount of args were passed through the command line
        filename=argv[1];
        cout<<"filename input value: "<<filename<<endl;
        string sourceNodeString = argv[2];
        sourceNode = stoi(sourceNodeString);
        cout<<"sourceNode input value: "<<sourceNode<<endl;

        //pass the name to populate the adj matrix
        //use this adj matrix in bfs and print output
        int**adjMatrix;
        adjMatrix=readInAdjMatrix(filename, n);
        cout<<"main(): Value of n: "<<n<<endl;
        printAdjMatrix(adjMatrix, n);
        //bfs(adjMatrix)
        //print result^^^



    }else if (argc==2){
        cout<<"Please append both a filename and a source node value in the format: ./main filename.txt #"<<endl;
        return 0;
    }
    //readInAdjMatrix("graph1.txt");
}

int**readInAdjMatrix(string fileName, int&n){
    cout<<"ACTIVE: readInAdjMatrix()"<<endl;
    std::ifstream ifs;
    ifs.open(fileName, ios::in|ios::binary);
    if(!ifs){
        cerr<<"Cannot open file: "<<fileName<<endl;
        return NULL;
    }
    string rowData;
    if(ifs.is_open()){
        n=0;
        while(getline(ifs, rowData)){
            n++;
        }
        cout<<"readAdjMatrix(): Value of n: "<<n<<endl;

        ifs.clear();
        ifs.seekg(0);

        int nums[n*n];
        int counter=0;
        while(getline(ifs, rowData, ' ')){
            //cout<<"rowData: " << rowData<<endl;
            nums[counter]=stoi(rowData);
            //cout<<"nums["<<counter<<"]: "<<nums[counter]<<endl;
            counter++;
        }




        int**returnPtr=0;
        returnPtr = new int*[n];
        int counter2 = 0;
        for (int i = 0; i < n; ++i) {
            returnPtr[i]=new int[n];
            for (int j = 0; j < n; ++j) {
                returnPtr[i][j]= nums[counter2];
                counter2++;
            }
        }
//        int i=0;
//        int j=0;
//        while(getline(ifs, rowData, ' ')){
//            if (j<n){
//
//                returnPtr[n][j]= stoi(rowData);
//                j++;
//            }else {
//                returnPtr[n]=new int[n];
//                i++;
//            }
//        }
        return returnPtr;
    }
    return NULL;
}

void printAdjMatrix(int**adjMatrix, int n){
    cout<<"ACTIVE: printAdjMatrix()"<<endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }

}


























//

//    int n = 10;
//
//    int adjMatrix[n][n];
//
//    node vertices[n];
//    node start;
//    char s;
//    for (int i = 0; i < n; ++i) {
//        vertices[i].val = i;
//    }
//



//
//
//    //num vertices
//    int v = 5;
//    vector<vector<int> > adj;
//    adj = vector<vector<int> >(v,vector<int>(v,0));
//
//    addEdge(0,1, adj);
//
//
//
//    cout<<"end";
//
//    return 0;











////
//// Created by Ashton Hess on 2/19/22.
////
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void addEdge(int x, int y, vector<vector<int> > adj){
//    adj[x][y]=1;
//    adj[y][x]=1;
//}
//
//int main(int argc, char*argv[]){
//
//    //num verticies
//    int v = 5;
//    vector<vector<int> > adj;
//    adj = vector<vector<int> >(v,vector<int>(v,0));
//
//    addEdge(0,1, adj);
//
//    cout<<"end";
//
//    return 0;
//}

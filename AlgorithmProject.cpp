#define NIL 0
#define INF 10000
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
int num_of_edge,num_of_vertex, graph[101][101] = { };
int d[101], p[101], weight_matrix[101][101] = { };
int rampura=1,badda=2,gulshan=3,banasree=4,khilgaon=5;
list<int> w,q,q_dis;
list<int>::iterator it,jt,kt;



void dijkstra(int s)
{
    int i,j,q_d[101],q_c=0;
    for (i = 0; i < 101; i++)
    {
        d[i] = INF;
        p[i] = NIL;
    }
    d[s] = 0;
    q.push_back(s);
    q_dis.push_back(0);
    for(i=1; i<=num_of_vertex; i++) {
        if(i!=s) {
            q.push_back(i);
            q_dis.push_back(INF);
        }
    }
    int temp,min_q,min_q_index,u;
    while(!q.empty())
        {

            min_q = q_dis.front();
            u=q.front();

            for(jt=q.begin(),it=q_dis.begin(),q_c=0,min_q_index=1; jt!=q.end() and it!=q_dis.end(); it++,jt++)
            {
                q_c++;
                if( *it < min_q )
                {
                    min_q=*it;
                    u=q_c;
                }

            }

        w.push_back(u);
        for(i=1; i<=num_of_vertex ; i++)
        {
            if(graph[u][i]==1)
            {
                if( d[i]>d[u]+ weight_matrix[u][i])
                {
                    d[i]=d[u]+weight_matrix[u][i];

                    p[i]=u;
                }
            }
        }

        q.pop_front();
        while( ! q_dis.empty())
        {
            q_dis.pop_front();
        }
        for( it = q.begin(); it!= q.end(); it++) {
            temp = *it;

            q_dis.push_back( d[temp] );
        }

    }
}
void dis_from_source_to_all_loc()
{
    int i;
    ofstream outf("dijkstra_output.txt");
    outf<<"Dijkstra Algorithm shortest path:"<<endl;
    cout<<"LOCATION:"<<endl;
    cout<<setw(15)<<"RAMPURA"<<setw(15)<<"BADDA " << setw(15)<< "GULSHAN" << setw(15) << "BANASREE" <<setw(15) <<"KHILGAON" <<endl;
    for(i=1; i<=num_of_vertex; i++)
    {
        cout<<setw(15)<<i;
        outf<<i<<"\t";

    }
    cout<<endl<<"Final Distance:"<<endl;

    for(i=1; i<= num_of_vertex; i++)
    {
        cout<<setw(12)<<d[i]<<setw(3)<<"KM";
        outf<<d[i]<<"\t";

    }
}

void location(int s)
{
        int loc=0,j;
         int min_dis = INF ;
        for(j=1;j<=num_of_vertex;j++)
            {
                if( ( j!=s ) && min_dis > d[j])
                {
                    min_dis=d[j];
                    loc=j;
                }

            }


        cout<<endl<<endl<<endl;
        if(s==rampura)
        {
            cout<<endl<<"NEAREST HOSPITAL'S  FROM RAMPURA IS ABOUT:"<<min_dis<<"KM"<<endl;

        }
        else if(s==badda)
        {
            cout<<endl<<"NEAREST HOSPITAL'S  FROM BADDA IS ABOUT:"<<min_dis<<"KM"<<endl;

        }
        else if(s==gulshan)
        {
            cout<<endl<<"NEAREST HOSPITAL'S  FROM GULSHAN IS ABOUT:"<<min_dis<<"KM"<<endl;

        }
        else if(s==banasree)
        {
            cout<<endl<<"NEAREST HOSPITAL'S  FROM BANASREE IS ABOUT:"<<min_dis<<" KM"<<endl;

        }
        else if(s==khilgaon)
        {
            cout<<endl<<"NEAREST HOSPITAL'S  FROM KHILGAON IS ABOUT:"<<min_dis<<" KM"<<endl;

        }


}
void hospital_name(int s)
{
        int loc=0,j;
         int min_dis = INF ;
          for(j=1;j<=num_of_vertex;j++)
             {
                 if( ( j!=s ) && min_dis > d[j])
                 {
                     min_dis=d[j];
                     loc=j;
                 }

             }



        if(loc==rampura)
        {
            cout<<endl<<"NEAREST HOSPITALS ARE LOCATED AT  : RAMPURA"<<endl;
            cout<<endl<<endl;
            cout<<"---------HOSPITALS NAME----------"<<endl;

            cout<<"DIABETIC HOSPITAL"<<endl;
            cout<<"EMERGENCY NUMBER: +8802-8857828"<<endl;
            cout<<"RATINGS: 3.2"<<endl;
            cout<<"OPEN: 24 HOURS"<<endl;
            cout<<endl<<endl<<endl;




        }
        else if(loc==badda)
        {
             cout<<endl<<"NEAREST HOSPITAL'S  IS LOCATED AT   : BADDA"<<endl;
              cout<<endl<<endl;

             cout<<"---------HOSPITALS NAME----------"<<endl;

             cout<<"BADDA GENERAL HOSPITAL"<<endl;
             cout<<"EMERGENCY NUMBER: +8802-8857828"<<endl;
             cout<<"RATINGS: 3.7"<<endl;
             cout<<"OPEN: 24 HOURS"<<endl;
             cout<<endl<<endl<<endl;

             cout<<"ASIAN HOSPITAL"<<endl;
             cout<<"EMERGENCY NUMBER: +8801711-381302"<<endl;
             cout<<"RATINGS: 3.7"<<endl;
             cout<<"OPEN: 24 HOURS"<<endl;
             cout<<endl<<endl<<endl;


        }
        else if(loc==gulshan)
        {
            cout<<endl<<"NEAREST HOSPITAL'S  IS LOCATED AT P : GULSHAN"<<endl;
            cout<<endl<<endl;

            cout<<"          ---------HOSPITALS NAME----------"<<endl;

            cout<<"             SHAHABUDDIN MEDICAL COLLEGE HOSPITAL"<<endl;
            cout<<"             EMERGENCY NUMBER: +8802-9863387"<<endl;
            cout<<"             RATINGS: 3.9"<<endl;
            cout<<"             OPEN: 24 HOURS"<<endl;
            cout<<endl<<endl<<endl;

            cout<<"             UNITED HOSPITAL"<<endl;
            cout<<"             EMERGENCY NUMBER: +8802-8836000 "<<endl;
            cout<<"             RATINGS: 3.8"<<endl;
            cout<<"             OPEN: 24 HOURS"<<endl;
            cout<<endl<<endl<<endl;


        }
        else if(loc==banasree)
        {
            cout<<endl<<"NEAREST HOSPITAL'S  IS LOCATED AT  : BANASREE"<<endl;
            cout<<endl<<endl;
            cout<<"             ---------HOSPITALS NAME----------"<<endl;

            cout<<"                FARAZY HOSPITAL"<<endl;
            cout<<"                EMERGENCY NUMBER: +880 1882-084414"<<endl;
            cout<<"                RATINGS: 3.2"<<endl;
            cout<<"                OPEN: 24 HOURS"<<endl;
            cout<<endl<<endl<<endl;

            cout<<"               AL-RAJI HOSPITAL"<<endl;
            cout<<"               EMERGENCY NUMBER: +8801766-118855 "<<endl;
            cout<<"               RATINGS: 3.4"<<endl;
            cout<<"               OPEN: 24 HOURS"<<endl;
            cout<<endl<<endl<<endl;



        }
        else if(loc==khilgaon)
        {
             cout<<endl<<"NEAREST HOSPITAL'S  IS LOCATED AT  : KHILGAON"<<endl;
             cout<<endl<<endl;

             cout<<"               ---------HOSPITALS NAME----------"<<endl;

             cout<<"               KHIDMAH HOSPITAL "<<endl;
             cout<<"               EMERGENCY NUMBER: +8801711-063030"<<endl;
             cout<<"               RATINGS: 4"<<endl;
             cout<<"               OPEN: 24 HOURS"<<endl;
             cout<<endl<<endl;

            cout<<"                PEOPLE'S HOSPITAL"<<endl;
            cout<<"                EMERGENCY NUMBER: +8801971-010135 "<<endl;
            cout<<"                RATINGS: 4"<<endl;
            cout<<"                OPEN: 24 HOURS"<<endl;
            cout<<endl;

        }
    }




int main()
 {
    ifstream inf("input.txt");
    int a, b, i = 1, m, n, wait,max_vertex=0,max_temp,s,j;
    inf>>num_of_edge;
    for(i=1;i<=num_of_edge;i++){
        inf>>a;
        inf>>b;
        max_temp=max(a,b);
        if( max_temp > max_vertex)
        {
            max_vertex=max_temp;
        }
        inf>>wait;
        graph[a][b]=1;
        weight_matrix[a][b]=wait;
    }
    num_of_vertex=max_vertex;
   // cout << "The Adj Matrix is: " << endl;
    /*for (m = 1; m <= num_of_vertex; m++) {
        for (n = 1; n <= num_of_vertex; n++) {
            cout << graph[m][n] << "\t";
        }
        cout << endl;
    }
*/

    int choice,c1,c2,patient;
     cout<<endl<<endl<<endl<<"             ***************  WELCOME TO EMERGTENCY AMBULENCE SERVICE  ************"<<endl<<endl<<endl;
    while(1)
    {

    cout<<"                 FOR AMBULENCE OPERATOR USER PRESS 1"<<endl;
    cout<<"                 FOR PATIENT    USER         PRESS 2"<<endl;
    cout<<"                 ENTER YOUR CHOICE:";
    cin>>choice;
    cout<<endl;


    switch(choice)
    {
    case 1:
        cout<<"TO FIND THE SHORTEST DISTANCE FROM YOUR LOCATION TO PATEINT'S LOCATION PRESS 1"<<endl;
        cout<<"TO KNOW YOUR TOTAL BILL PRESS 2"<<endl;
        cout<<"FOR EXIT PRESS 3:"<<endl;
        cout<<"ENTER YOUR CHOICE:";
        cin>>c1;
        cout<<endl;

        switch(c1)
        {
         case 1:
             cout<<"IF THE STARTING LOCATION IS RAMPURA     ENTER 1"<<endl;
             cout<<"                        FOR BADDA       ENTER 2"<<endl;
             cout<<"                        FOR GULSHAN     ENTER 3"<<endl;
             cout<<"                        FOR BANASREE    ENTER 4"<<endl;
             cout<<"                        FOR KHILGAON    ENTER 5"<<endl;
             cout<<"ENTER YOUR LOCATION:"<<endl;
             cin>>s;
             cout<<"ENTER PATIENT'S LOCATION"<<endl;
             cin>>patient;
             dijkstra(s);
             cout<<"THE SHORTEST DISTANCE FROM YOUR LOCATION TO PATEINT'S LOCATION :"<<d[patient]<<"KM"<<endl<<endl;
             break;
         case 2:
             cout<<"IF THE PATIENT  LOCATION IS RAMPURA     ENTER 1"<<endl;
             cout<<"                        FOR BADDA       ENTER 2"<<endl;
             cout<<"                        FOR GULSHAN     ENTER 3"<<endl;
             cout<<"                        FOR BANASREE    ENTER 4"<<endl;
             cout<<"                        FOR KHILGAON    ENTER 5"<<endl;
             cout<<"ENTER PATIENT'S LOCATION"<<endl;
             cin>>s;
             dijkstra(s);
               int loc=0;
               int min_dis = INF ;
               for(j=1;j<=num_of_vertex;j++)
               {
                 if( ( j!=s ) && min_dis > d[j])
                 {
                    min_dis=d[j];
                    loc=j;
                 }
              }
             cout<<"TOTAL BILL : "<<d[loc]*100<<"TK"<<endl;
             break;



        }
        break;


    case 2:
        cout<<"TO KNOW THE SHORTEST  DISTANCE HOSPITAL LOCATION FROM  PATEINT'S LOCATION PRESS 1:"<<endl;
        cout<<"TO KNOW THE SHORTEST  DISTANCE HOSPITAL NAMES FROM  PATEINT'S LOCATION PRESS    2:"<<endl;
        cout<<"TO KNOW THE SHORTEST DISTANCE FROM PATIENT LO0CATION TO OTHERS LOCATION PRESS   3:"<<endl;
        cout<<"FOR EXIT PRESS 4:"<<endl;
        cout<<"ENTER YOUR CHOICE:";
        cin>>c2;
        switch(c2)
        {
        case 1:
             cout<<"IF THE STARTING LOCATION IS RAMPURA     ENTER 1"<<endl;
             cout<<"                        FOR BADDA       ENTER 2"<<endl;
             cout<<"                        FOR GULSHAN     ENTER 3"<<endl;
             cout<<"                        FOR BANASREE    ENTER 4"<<endl;
             cout<<"                        FOR KHILGAON    ENTER 5"<<endl;
             cout<<"ENTER PATIENT'S LOCATION:"<<endl;
             cin>>s;
             dijkstra(s);
             location( s);
             cout<<endl<<endl;
             break;
        case 2:

            cout<<"ENTER THE PATIENT LOCATION FIRST"<<endl;

            cout<<"IF THE PATIENT  LOCATION IS RAMPURA     ENTER 1"<<endl;
            cout<<"                        FOR BADDA       ENTER 2"<<endl;
            cout<<"                        FOR GULSHAN     ENTER 3"<<endl;
            cout<<"                        FOR BANASREE    ENTER 4"<<endl;
            cout<<"                        FOR KHILGAON    ENTER 5"<<endl;
            cout<<"ENTER LOCATION"<<endl;
            cin>>s;
                 dijkstra(s);
                 hospital_name( s);
             cout<<endl<<endl;


             break;
        case 3:

            cout<<"IF THE PATIENT  LOCATION IS RAMPURA     ENTER 1"<<endl;
            cout<<"                        FOR BADDA       ENTER 2"<<endl;
            cout<<"                        FOR GULSHAN     ENTER 3"<<endl;
            cout<<"                        FOR BANASREE    ENTER 4"<<endl;
            cout<<"                        FOR KHILGAON    ENTER 5"<<endl;
            cout<<"ENTER LOCATION"<<endl;
            cin>>s;
            dijkstra(s);
             dis_from_source_to_all_loc();
              cout<<endl<<endl;
             break;
        default:
            break;

        }
        default:
            break;



    }
    }

    return 0;

}





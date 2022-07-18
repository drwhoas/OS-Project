#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

#define N 10
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}
typedef struct
{
      int process_id, arrival_time, burst_time, priority;
      int queue1, ready;
}process_structure;

int Queue(int t1)
  {
    if(t1==0||t1==1||t1== 2||t1==3)
      {
        return 1;
      }
      else
      {
        return 2;
      }
}
    void memory_management()
    {
        int mem_block_size;
        int page_size,no_of_pages;
        int frame_number,offset;
        int logical_ad,physical_ad;
        int array1[100];
        int i;


        cout<<"\t\t**********Memory Management**********";

        cout<<"\n\n \t\t *Please insert integer values only* ";

        cout<<"\n\n\n Enter the memory block size       : ";
        cin>>mem_block_size;
        cout<<"\n Enter page size                   : ";
        cin>>page_size;

        no_of_pages=mem_block_size/page_size;

        cout<<"\n The number of pages available are : "<<no_of_pages;

        for(i=0;i<no_of_pages;i++)
        {
            cout<<"\n\n Enter the frame number of page number "   <<i+1<<":  ";
            cin>>array1[i];
        }

        {
            int choice=0;
            do
            {
                cout<<"\n\nEnter a logical address            : ";
                cin>>logical_ad;
                if(logical_ad>mem_block_size)
                    {
                        cout<<"\n\n \t\t\tThis location doesn't exist";
                    }
                else
                    {
                        frame_number=logical_ad/page_size;
                        offset=logical_ad%page_size;
                        physical_ad=(array1[frame_number]*page_size)+offset;
                        cout<<"\nPhysical address is                : "<<physical_ad;
                        cout<<"\n\n\t\tDo you want to continue(Yes:1  No:0)?      : ";
                        cin>>choice;
                        switch(choice)
                        {
                            case 1:
                                break;
                            case 0:
                                cout<<"\n\n\t\t\t\t______END______\n\n";
                                break;
                            default:
                                cout<<"\n\t\t\t****Invalid choice entered****\n\n";
                        }
                    }
            }while(choice==1);
        }
    }
void process_management()
{
      int limit, count, temp_process, time, j, y;
      process_structure temp;
      cout<<"Enter Total Number of Processes:\t"<<endl;
      cin>>limit;
      process_structure process[limit];
      for(count = 0; count < limit; count++)
      {
           cout<<"\nProcess ID:\t"<<endl;
            cin>>process[count].process_id;
            cout<<"Arrival Time:\t"<<endl;
            cin>>process[count].arrival_time;
            cout<<"Burst Time:\t"<<endl;
            cin>>process[count].burst_time;
            cout<<"Process Priority:\t"<<endl;
            cin>>process[count].priority;
            temp_process = process[count].priority;
            process[count].queue1 = Queue(temp_process);
            process[count].ready = 0;
      }
      time = process[0].burst_time;
      for(y = 0; y < limit; y++)
      {
        for(count = y; count < limit; count++)
        {
            if(process[count].arrival_time < time)
            {
                process[count].ready = 1;
            }
        }
        for(count = y; count < limit - 1; count++)
        {
            for(j = count + 1; j < limit; j++)
            {
                if(process[count].ready == 1 && process[j].ready == 1)
                    {
                if(process[count].queue1 == 2 && process[j].queue1 == 1)
                    {
                        temp = process[count];
                        process[count] = process[j];
                        process[j] = temp;
                    }
                    }
            }
        }
        for(count = y; count < limit - 1; count++)
            {
              for(j = count + 1; j < limit; j++)
                {
                  if(process[count].ready == 1 && process[j].ready == 1)
                    {
                  if(process[count].queue1 == 1 && process[j].queue1 == 1)
                    {
                  if(process[count].burst_time > process[j].burst_time)
                    {
                       temp = process[count];
                        process[count] = process[j];
                        process[j] = temp;
                    }
                else
                    {
                        break;
                    }
                    }
                    }
                }
            }
cout<<"\nProcess \tTime: \t To \t \n"<<process[y].process_id<<"\t\t"<<time<<"\t\t"<<time + process[y].burst_time;
time = time + process[y].burst_time;
   for(count = y; count < limit; count++)
    {
        if(process[count].ready == 1)
        {
        process[count].ready = 0;
        }
    }
}

}
void io_management()
{
    int i,j,k,requests,sized,sum=0,x,y,h;
    cout<<"Enter the size of disk\n";
    cin>>sized;
    cout<<"Enter number of requests\n";
    cin>>requests;
    cout<<"Enter the requests\n";
    vector <int> a(requests),l;
    for(i=0;i<requests;i++){
        cin>>a[i];
    }
    for(i=0;i<requests;i++){
        if(a[i]>sized){
            cout<<"Error, Unknown position\n";

        }
    }
    cout<<"Enter the head position\n";
    cin>>h;
    a.push_back(h);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<requests/2){
        for(i=k;i<a.size();i++){
            l.push_back(a[i]);
        }
        for(i=k-1;i>=0;i--){
            l.push_back(a[i]);
        }
    }
    else{
        for(i=k;i>=0;i--){
            l.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){
            l.push_back(a[i]);
        }
    }
    int temp=l[0];
    cout<<temp;
    for(i=1;i<l.size();i++){
        cout<<" -> "<<l[i]<<' ';
        sum+=abs(l[i]-temp);
        temp=a[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';

}
void file_management() {
   //2 random prime numbers
   double p,q,result,phi,n,message;
   cout<<"Enter value of p"<<endl;
   cin>>p;
   cout<<"Enter value of q"<<endl;
   cin>>q;
    n=p*q;//calculate n
    phi= (p-1)*(q-1);//calculate phi
   //public key
   //e stands for encrypt
   double e=7;
   //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
   while(e<phi) {
      result = gcd(e,phi);
      if(result==1)
         break;
      else
         e++;
   }
   //private key
   //d stands for decrypt
   //choosing d such that it satisfies d*e = 1 mod phi
   double d1=1/e;
   double d=fmod(d1,phi);
   cout<<"Enter Message"<<endl;
   cin>>message;
   double c = pow(message,e); //encrypt the message
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);
   cout<<"----------------------------"<<endl;
   cout<<"p = "<<p<<endl;
   cout<<"q = "<<q<<endl;
   cout<<"n = pq = "<<n<<endl;
   cout<<"phi = "<<phi<<endl;
   cout<<"e = "<<e<<endl;
   cout<<"d = "<<d<<endl;
   cout<<"Original Message = "<<message<<endl;
   cout<<"Encrypted message = "<<c<<endl;
   cout<<"Decrypted message = "<<m<<endl;
}


int main()
{
    int choice;
    cout<<" *************** MULTIPROCESSING OPERATING SYSTEM *************** ";
    do{
    cout<<"Choose :\n\n"<<endl;
    cout<<"1. Process Management"<<endl<<"2. I/O Management"<<endl<<"3. Memory Management"<<endl
    <<"4. File Management"<<endl<<"5. Exit\n\n"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Process Management "<<endl;
        process_management();
        break;

    case 2:
        cout<<"I/O Management "<<endl;
        io_management();
        break;

    case 3:
        memory_management();
        break;

    case 4:
        cout<<"File Management "<<endl;
        file_management();
        break;

    case 5:
        cout<<"Thank You"<<endl;
        break;

    default:
        cout<<"Invalid Choice. Please choose again: ";
        break;
    }
    }while(choice!=5);
}

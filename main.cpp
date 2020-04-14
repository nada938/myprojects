#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    int grade;
};
int countkeyword(string keyword,string phrase);
void getStudentData(student arr[10]);
void highest_grade(student arr[10]);
void distribution( student arr[10]);
int sum (int **arr,int r,int c);

int choice;


int main()
{
    do
    {
        cout<<"please enter 1 for problem1 and 2 for problem2 and 3 for problem3 and 4 for Exit : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
           {
            string keyword,phrase;
            cout<<"ENTER a KEYWORD : ";
            cin>>keyword;
            cout<<"ENTER A PHRASE : ";
            cin.ignore();
            getline(cin,phrase);
            cout<<"The keyword "<<"\""<<keyword<<"\""<<" "<<"appeared"<<" "<<countkeyword(keyword,phrase)<<" "<<"times in your phrase"<<endl;
            break;
           }

        case 2:
            {
             int row,col;
             cout<<"Enter the number of rows"<<endl;
             cin>>row;
             cout<<"Enter the number of columns"<<endl;
             cin>>col;
             cout<<"Enter the integer elements :"<<endl;
             int **arr;
             arr = new int* [row];
             for (int i=0; i < row; i++)
             arr[i] = new int[col];

            for (int i=0; i < row; i++)
            {
             for (int j=0; j < col; j++)
             {
                cin>>arr[i][j];
             }
            }
             cout<<sum(arr,row,col)<<endl;
             break;

            }

        case 3:
              {
                student arr[10];
                cout<<"Enter Student name and his grade"<<endl;
                getStudentData(arr);
                highest_grade(arr);
                distribution(arr);

                break;
              }


        case 4:
           {
               break;
           }

        default:
            {
               cout<<"That is invalid choice"<<endl;
               break;
            }
        }
    }while(choice!=4);

    return 0;
}

int countkeyword(string keyword,string phrase)
{
    int j=0,b=0;
for(int i = 0; i < phrase.length(); i++)
{
    if (phrase[i] == keyword[j])
	 {
	     j++;
	     if(j==keyword.size())
         {
             b++;
             j=0;
         }
    }
}
return b;
}

void getStudentData(student arr[10])
{
    float max;
    int i;
    int m = 0;
    max = arr[0].grade;
    for(int i=0;i<10;i++)
    {
        cin>>arr[i].name>>arr[i].grade;
    }

   cout<<"**"<<endl;
   cout<<"Student name"<<"\t"<<"Student grade"<<endl;
    for(int i=0;i<10;i++)
    {

        cout<<arr[i].name<<"\t\t"<<arr[i].grade<<endl;
    }


}

void highest_grade(student arr[10])
{
    int m;
    int max = arr[0].grade;
    for(int i=0;i<10;i++)
      {
        if(arr[i].grade>max)
        {
            max = arr[i].grade;
            m = i;

        }

        else
        {
            continue;
        }
      }


    cout<<arr[m].name<<" "<<"got the highest grade in the class"<<" and his grade is : "<<arr[m].grade<<endl;
}



void distribution( student arr[10])
{
    cout << "0-9: ";
	for (int i = 0; i < 10; i++){
		 if  (arr[i].grade>= 0 && arr[i].grade <= 9)
			{
			cout<<"* ";
			}
	}
    cout<<"\n";

	cout << "10-19: ";
		for (int i = 0; i < 10; i++){
		 if  (arr[i].grade >= 10 && arr[i].grade <= 19)
			cout << "* ";
		}
		cout<<"\n";
	cout << "20-29: ";
		for (int i = 0; i < 10; i++){
		 if  (arr[i].grade >= 20 && arr[i].grade<= 29)
			cout << "* ";
		}
		cout<<"\n";

	cout << "30-39: ";
		for (int i = 0; i < 10; i++){
		 if  (arr[i].grade>= 30 && arr[i].grade<= 39)
         {
             //cout<<"hi\n";
			cout << "* ";
		}
		}
		cout<<"\n";

	cout << "40-49: ";
		for (int i = 0; i < 10; i++){
		 if (arr[i].grade>= 40 && arr[i].grade<= 49)
			{
			cout << "* ";
			}
		}
		cout<<"\n";

	cout << "50-59: ";
		for (int i = 0; i < 10; i++){
		 if (arr[i].grade>= 50 && arr[i].grade<= 59)
			cout << "* ";
		}
		cout<<"\n";

	cout << "60-69: ";
		for (int i = 0; i < 10; i++){
		 if (arr[i].grade>= 60 && arr[i].grade<= 69)
			cout << "* ";
		}
		cout<<"\n";

	cout << "70-79: ";
		for (int i = 0; i < 10; i++){
		 if (arr[i].grade >= 70 && arr[i].grade <= 79)
			cout << "* ";
		}
		cout<<"\n";

	cout << "80-89: ";
		for (int i = 0; i < 10; i++){
		 if (arr[i].grade>= 80 && arr[i].grade<= 89)
			cout << "* ";
		}
		cout<<"\n";

	cout << "90-99: ";
		for (int i = 0; i < 10; i++){
         if (arr[i].grade>= 90 && arr[i].grade<= 99)
			cout << "* ";
		}
		cout<<"\n";

	cout << "100:";
		for (int i = 0; i < 10; i++){
		 if (arr[i].grade== 100)
			cout << " * ";
		}
		cout<<"\n";
}

int sum (int **arr,int row,int col) {
    int r=0;
    int c=0;
    int sumpath=arr[r][c];
    cout<<arr[r][c]<<" + ";

    for(int i=0;true;i++) {


         if (arr[r][c] <= arr[r][c + 1]&& c != col - 1) {
            if (arr[r][c] == arr[r][c + 1])
                c++;
            else {
                cout<<arr[r][c + 1]<< " + ";
                sumpath = sumpath + arr[r][c + 1];
                c ++;
            };

        } else if (r != row - 1&& arr[r][c] <= arr[r + 1][c] ) {
            if (arr[r][c] == arr[r + 1][c])
                r++;
            else {
                    cout<<arr[r+1][c ]<< " + ";
                sumpath = sumpath + arr[r+1][c];
                r ++;
            }
        }
         else
        break;

    }

    cout<<" 0 =";
    return sumpath;
}

#include<iostream>
#include<fstream>
#include<list>

using namespace std;

int** matrix_1(int numArgument)
{
//  Khoi tao matrix
	int** arr;
	arr= new int*[numArgument];
	for(int i=0;i<numArgument;i++)
	{
		arr[i]= new int[numArgument];
	}	
//	Nhap du lieu vao matrix
	std::ifstream fileInput("input1.txt");
	if(fileInput.fail())
	{
		std::cout<<"Failed to open file"<<endl;
	}
	for(int i=0; i<numArgument; i++)
	{
		for(int j=0; j<numArgument; j++)
		{
			if(!fileInput.eof())
				fileInput>>arr[i][j];
		}
	}
	fileInput.close();
	return arr;
}
void nextList(int argument)
{
	ofstream ofs_1("input1_1.txt");
	ofstream ofs_2("input1_2.txt");
	list<int> arr[argument];
	for(int i=0; i<argument; i++)
	{
		for(int j=0; j<argument; j++)
		{
			if(matrix_1(argument)[i][j]==1)
			{
				arr[i].push_back(j);
			}
		}
	}
	for(int i=0; i<6; i++)
	{
		int j=0;
		ofs_1<<char('a'+i)<<" : ";
		for(int x: arr[i])
		{
			ofs_1<<char('a'+x)<<" ";
			j++;
		}
		ofs_1<<";"<<endl;
	}
	for(int i=0; i<6; i++)
	{
		for(int x: arr[i])
		{
			if(x>i)
				ofs_2<<char('a'+i)<<char('a'+x)<<";"<<endl;
		}
	}
}
void input1_1_To_Out1_1(int argument)
{
	ofstream out_1("output1_1.txt");
	ifstream fileIn("input1_1.txt");
	list<char> arr[argument];
	char a='a';int num=0;int max=1;
	out_1<<"Danh sach canh va bac 1:\n"<<endl;
	while(!fileIn.eof())
	{
		char c;
		fileIn>>c;
		if((a-c)<10&&(c-a)!=0)
		{
			if((c-a)>0)
				out_1<<a<<" --- "<<c<<endl;
			num++;
		}
		if(c==';'&&max<=argument)
		{
			out_1<<"+ Dinh "<<a<<" co bac la: "<<num<<endl;
			a=char(int(a)+1);
			num=0;max++;
		}
	}
}
void input1_2_To_Out1_2(int argument)
{
	ofstream out_2("output1_2.txt");
	ifstream fileIn("input1_2.txt");
	list<char> arr[argument];
	char c[2];char a ='a';
	for(int i=0; i<10; i++)
	{
		if(!fileIn.eof())
		{
			fileIn>>c[0];
			fileIn>>c[1];
			arr[c[0]-a].push_back(c[1]);
			arr[c[1]-a].push_back(c[0]);
		}
	}
	out_2<<"Danh sach ke tu danh sach canh 1_2:  "<<endl;
	for(int i=0; i<6; i++)
	{
		int j=0;
		out_2<<char('a'+i)<<" : ";
		for(char x: arr[i])
		{
			out_2<<x<<" ";
			j++;
		}
		out_2<<";"<<endl;
	}
	out_2<<"\nBac cua tung dinh: "<<endl;
	for(int i=0; i<6; i++)
	{
		out_2<<"+ Dinh "<<char(a+i)<<" co bac la: "<<arr[i].size()<<endl;
	}
}
int main()
{
	nextList(6);
	input1_1_To_Out1_1(6);
	input1_2_To_Out1_2(6);
	return 0;
}

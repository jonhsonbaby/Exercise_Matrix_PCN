#include<iostream>
#include<fstream>
#include<list>

using namespace std;

int** matrix_2(int numArgument)
{
//  Khoi tao matrix
	int** arr;
	arr= new int*[numArgument];
	for(int i=0;i<numArgument;i++)
	{
		arr[i]= new int[numArgument];
	}	
//	Nhap du lieu vao matrix
	std::ifstream fileInput("input2.txt");
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
	ofstream ofs_1("input2_1.txt");
	ofstream ofs_2("input2_2.txt");
	list<int> arr[argument];
	for(int i=0; i<argument; i++)
	{
		for(int j=0; j<argument; j++)
		{
			if(matrix_2(argument)[i][j]==1)
			{
				arr[i].push_back(j);
			}
		}
	}
	// Danh sach ke
	for(int i=0; i<5; i++)
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
	// Danh sach canh
	for(int i=0; i<5; i++)
	{
		for(int x: arr[i])
		{
			ofs_2<<char('a'+i)<<" : "<<char('a'+x)<<endl;
		}
	}
}
void input2_1_To_Out2_1(int argument)
{
	ofstream out_2("output2_1.txt");
	ifstream fileIn("input2_1.txt");
	list<char> arr[argument];
	char a='a';int sum1[argument];int sum2[argument];
	for(int i=0; i<argument; i++){sum2[i]=0;sum1[i]=0;}
	out_2<<"Danh sach canh 2 :"<<endl;
	while(!fileIn.eof())
	{
		char c;
		fileIn>>c;
		if((a-c)<10&&(c-a)!=0)
		{
			sum2[c-'a']+=1;
			out_2<<a<<" --- "<<c<<endl;
			sum1[a-'a']+=1;
		}
		if(c==';')
		{
			a=char(int(a)+1);
		}
	}
	out_2<<"Bac cua dinh :"<<endl;
	for(int i=0; i<argument; i++)
	{
		out_2<<"deg("<<char('a'+i)<<")+ = "<<sum2[i]<<endl;
		out_2<<"deg("<<char('a'+i)<<")- = "<<sum1[i]<<"\n"<<endl;
	}
	
}
int main()
{
	nextList(5);
	input2_1_To_Out2_1(5);
	return 0;
}

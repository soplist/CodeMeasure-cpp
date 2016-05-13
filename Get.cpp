#include <iostream> 
#include <vector>
#include <iomanip>  
#include <fstream>
#include <string>
#include <io.h>

#define NULL 0

/*linux and windows file line is not same*/
/*use the method of approach*/
/*jquery ui css*/

using namespace std; 
     
class Get  
{
private:
	int count;
public:
	Get();
	void setCount(int count);
    int getCount();
};
Get::Get()
{
}
void Get::setCount(int count)
{
	this->count=count;
}

int Get::getCount()
{
	return count;
}
static int fileCount = 0;
int getCodecount(string path)  
{  
	int count = 0;
	
    long   hFile   =   0;  
    struct _finddata_t fileinfo;  
    string p;  
	if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  
    {  
        do  
        {  
            if((fileinfo.attrib &  _A_SUBDIR))  
            {  
                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  
                    count+=getCodecount( p.assign(path).append("\\").append(fileinfo.name));  
            }  
            else  
            {  
				char buf[1024];
                ifstream infile; 
				
				//cout << p.assign(path).append("\\").append(fileinfo.name) << endl; 
				
				
				string str_1 = p.assign(path).append("\\").append(fileinfo.name);
                //int str_1_len = str_1.length();
				//cout << str_1[str_1_len-1] << endl; 
                const char *fp = str_1.c_str();

                if(strstr(fp,".jsp")!=NULL||strstr(fp,".java")!=NULL||strstr(fp,".properties")!=NULL
					||strstr(fp,".xml")!=NULL||strstr(fp,".css")!=NULL)
				{
				    //cout << fp << endl; 
					fileCount++;
	                infile.open(fp);
				    if(infile.is_open())
	                {
		                while(infile.good()&&!infile.eof())//  
		                {
			                memset(buf,0,1024);  
                            infile.getline(buf,1024);  
			                count++;
		                }
		                infile.close();
	                }
                }
            }  
        }while(_findnext(hFile, &fileinfo)  == 0);  
        _findclose(hFile);  
    }  
    return count;
}

int main() { 
    char * filePath = "D:\\test";  
	int count = getCodecount(filePath); 
	cout << "code count="<< count << endl; 
	cout << "file count="<< fileCount << endl;
    return 0; 
} 
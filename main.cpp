    #include<iostream>
    #include<fstream>
    #include<string>
    #include<vector>
    #include<algorithm>
    #include <stdlib.h>
    using namespace std;


	float everything(char c,float num){
		cout<<"I set:"<<c<<" "<<num<<endl;
		return 0.0;
	}

    float getXchord(float x){
      return 0;
    }

    float setXchord(float x){
      cout<<"Setup the X chord:"<<x;
      while(x-getXchord(x)){
      }
      cout<<"done"<<endl;
      return getXchord(x);
    }

    bool interpreter(string gline){
      int j=0;
      int i=0;
      cout<<gline<<endl;
      for(i=0;i<=gline.size();i++){
        if(gline[i]==' ' || gline[i]=='\0' ){
          string tmp(gline,j+1,i-1);
          transform(tmp.begin(), tmp.end(), tmp.begin(),(int (*)(int))tolower);
          //cout<<"tmp value:"<<tmp<<" i:"<<i<<" j:"<<j<<endl;
          string num(tmp,1,tmp.size());
          float f_num;
          string::size_type sz;
          f_num= atof(num.c_str());
          cout<<f_num<<" "<<endl;
	  switch(gline[j]){
		case 'x':
			setXchord(f_num);
			break;
        	default:
			everything(gline[j+1],f_num);
			break;
	}
	j=i;
      }
    }
      return 0;
    }

    int main(){

      string name;
      string tmp;
      fstream input;
      vector<string> sv_input;

      input.open("rectangle.gcode");
      while(getline(input,tmp,'\n')){
        sv_input.push_back(tmp);
      }

      for(int i=0;i<sv_input.size();i++){
        if(interpreter(sv_input[i])){
          cout<<"error!"<<endl;
        }
      }

      input.close();
      return 0;
    }

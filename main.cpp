    #include<iostream>
    #include<fstream>
    #include<string>
    #include<vector>
    #include<algorithm>
    #include<stdlib.h>
    #include<sstream>
    using namespace std;

    void everything(char c,float f_num){
      cout<<c<<"_"<<f_num<<endl;
    }

    bool setHead(int num){
      cout<<"I set the head:..."<<num<<endl;
      return true;
    }

    float getXchord(float x){
      return 0;
    }

    float setXchord(float x){
      cout<<"Setup the X chord:"<<x;
      //while(x-getXchord(x)){
      //}
      cout<<"done"<<endl;
      return getXchord(x);
    }



    float getYchord(float x){
      return 0;
    }

    float setYchord(float x){
      cout<<"Setup the Y chord:"<<x;
      //while(x-getYchord(x)){
      //}
      cout<<"done"<<endl;
      return getYchord(x);
    }


    float getZchord(float x){
      return 0;
    }

    float setZchord(float x){
      cout<<"Setup the Y chord:"<<x;
      //while(x-getZchord(x)){
      //}
      cout<<"done"<<endl;
      return getZchord(x);
    }



    bool interpreter(string gline){
      int j=-1;
      int i=0;
      cout<<gline<<endl;
      for(i=0;i<=gline.size();i++){
        if(gline[i]==' ' || gline[i]=='\0' ){
          string tmp(gline,j+1,i);
          transform(tmp.begin(), tmp.end(), tmp.begin(),(int (*)(int))tolower);
          string num(tmp,1,tmp.size()-1);
          float f_num;
        //  f_num= atof(num.c_str());
          stringstream(num) >> f_num;
          cout<<tmp[j+1]<<endl;
          switch(tmp[j+1]){
		          case 'x':
			              setXchord(f_num);
			              break;
              case 'y':
  			            setYchord(f_num);
  			            break;
              case 'z':
    			          setZchord(f_num);
    			          break;
              case 'g':
                    setHead(f_num);
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

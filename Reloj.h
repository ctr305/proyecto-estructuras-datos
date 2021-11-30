#include <iostream>
#include <cmath>
#include <unistd.h>

int getDigits(int i);

int min = 0, seg = 0, digitsMin, digitsSeg;
std::string displayMin, displaySeg;

std::string ReturnTime(int temp){
  std::string time="";


  float minAux = temp/60;
  min = std::floor(minAux);

  seg=temp-(min*60);

  if(min>99){
    min=99;
  }

  if(getDigits(min)<2){
    time+="0"+std::to_string(min);
  }else{
    time+=std::to_string(min);
  }

  time+=":";

  if(getDigits(seg)<2){
    time+="0"+std::to_string(seg);
  }else{
    time+=std::to_string(seg);
  }

  return time;
}

int getDigits(int i){
  int digits=0, aux=i;
  while(aux>0){
      aux=aux/10;
      digits++;
    }
  return digits;
}

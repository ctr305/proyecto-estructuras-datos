#include <iostream>
#include <unistd.h>
#include <cmath>
int getDigits(int i);

int minutos = 0, seg = 0, digitsMin, digitsSeg;
std::string displayMin, displaySeg;

std::string ReturnTime(int temp){
  std::string time="";

  float minAux = temp/60;
  minutos = std::floor(minAux);

  seg=temp-(minutos*60);

  if(minutos>99){
    minutos=99;
  }

  if(getDigits(minutos)<2){
    time+="0"+std::to_string(minutos);
  }else{
    time+=std::to_string(minutos);
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

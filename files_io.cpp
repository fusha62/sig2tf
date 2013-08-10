#include <iostream>
#include <vector>
#include <sndfile.hh>

int main(){
  // open input file
  SndfileHandle infile("./a.wav",SFM_READ);
  
  // print file infomation
  std::cout << infile.samplerate() << std::endl;
  std::cout << infile.channels() << std::endl;

  // read frames
  std::vector<short int> input(infile.frames());
  infile.readf(input.data(), infile.frames());
  // print input 
   for (int i = 0; i < input.size(); ++i) {
     std::cout << ' ' << input[i] << std::endl;
   }

  return 0;
}

#include <iostream>
#include <vector>
#include <sndfile.hh>

int main(){
  // open input file
  SndfileHandle infile("./a.wav",SFM_READ);
  if (not infile) return -1;
  
  // print file infomation
  std::cout << infile.format() << std::endl;
  std::cout << infile.samplerate() << std::endl;
  std::cout << infile.channels() << std::endl;

  // read frames
  std::vector<short int> input(infile.frames());
  infile.readf(input.data(), infile.frames());

  // print input 
   // for (int i = 0; i < input.size(); ++i) {
   //   std::cout << ' ' << input[i] << std::endl;
   // }
   
   // write output file
   const char* outfilename="foo.wav";
   SndfileHandle outfile(outfilename, SFM_WRITE,
			 infile.format(), infile.channels(), infile.samplerate());
   if (not outfile) return -1;
   outfile.write(input.data(), input.size());
   

  return 0;
}

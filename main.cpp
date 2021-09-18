#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>

class Game{
  // 10 spots
  const unsigned NUM_SPOTS = 10;
  std::vector<std::vector<std::pair<unsigned, unsigned>>> payOff;

  
  static unsigned dist(unsigned x, unsigned y){
    if (x > y){
      return x - y;
    }
    return y - x;
  }

  void genPair(unsigned& payOffA, unsigned& payOffB,
      unsigned spot, unsigned aLoc, unsigned bLoc){
      unsigned distToA = dist(spot, aLoc);
      unsigned distToB = dist(spot, bLoc);
      if (distToA < distToB){
        // std::cout << "Player 1 gains 10 from spot " << spot << ".\n";  
        payOffA += 10;
      } else if (distToA == distToB){
        for (unsigned i = 1; i <= 2; ++i){
          // std::cout << "Player " << i << " gains 5 from spot " << spot << ".\n"; 
        }
        payOffA += 5;
        payOffB += 5;
      } else {
        payOffB += 10;
      }
  }

public:

  Game(){
    payOff.resize(NUM_SPOTS, std::vector<std::pair<unsigned, unsigned>>(NUM_SPOTS,
       std::make_pair<unsigned, unsigned>(0, 0)));
  }

  void calculatePayOff(){
    for (unsigned a = 1; a <= NUM_SPOTS; ++a){
      for (unsigned b = 1; b <= NUM_SPOTS; ++b){
        std::pair<unsigned, unsigned>& payOffPair = payOff[a-1][b-1];
        for (unsigned spot = 1; spot <= NUM_SPOTS; ++spot){
          genPair(payOffPair.first, payOffPair.second, spot, a, b);
        }
      }
    }
  }
  
  void printPayOff(){
    const unsigned width = 5;
    const char separator = ' ';
    std::cout << std::setw(width) << std::setfill(separator);
    for (unsigned i = 1; i <= NUM_SPOTS; ++i){
       std::cout << std::setw(width + 4) << std::setfill(separator) << i ;
    }
    std::cout << "\n";
    for (unsigned i = 1; i <= NUM_SPOTS; ++i){
      std::cout << std::setw(width) << std::setfill(separator) << i;
      for (unsigned j = 1; j <= NUM_SPOTS; ++j){
        std::cout << std::setw(width) << std::setfill(separator) <<
         payOff[i-1][j-1].first <<  ", " << payOff[i-1][j-1].second;
      }
      std::cout << "\n";
    }
  }

  void genLatex(){
    const unsigned width = 5;
    const char separator = ' ';
    std::cout << std::setw(width) << std::setfill(separator);
    for (unsigned i = 1; i <= NUM_SPOTS; ++i){
      std::cout << " & ";
       std::cout << std::setw(width + 4) << std::setfill(separator) << "$" << i << "$";
    }
    std::cout << "\n";
    for (unsigned i = 1; i <= NUM_SPOTS; ++i){
      std::cout << " & ";
      std::cout << std::setw(width) << std::setfill(separator) << "$" << i << "$";
      std::cout << " & ";
      for (unsigned j = 1; j <= NUM_SPOTS; ++j){
        std::cout << std::setw(width) << std::setfill(separator) 
         << "$" << payOff[i-1][j-1].first <<  ", " << payOff[i-1][j-1].second << "$";
        if (j != NUM_SPOTS){
          std::cout << " & ";
        }
      }
      std::cout << "\\\\\\cline{2-12}\n";
    }
  }
};


int main(){
  // happy coding :)
  Game g;
  g.calculatePayOff();
  g.genLatex();
  // std::cout << "Hello World!" << std::endl;
}

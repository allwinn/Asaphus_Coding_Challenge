/**
 * @file asaphus_coding_challenge.cpp
 * @version 1.1
 * @copyright Copyright (c) 2022 Asaphus Vision GmbH
 *
 * The goal is to implement the mechanics of a simple game and write test cases for them.
 * The rules of the game are:
 * - There are two types of boxes, green and blue. 
 * - Both can absorb tokens of a given weight, which they add to their own total weight. 
 * - Both are initialized with a given initial weight.
 * - After a box absorbs a token weight, it outputs a score. 
 * - Green and blue boxes calculate the score in different ways:
 * - A green box calculates the score as the square of the mean of the 3 weights that it most recently absorbed (square of mean of all absorbed weights if there are fewer than 3).
 * - A blue box calculates the score as Cantor's pairing function of the smallest and largest weight that it has absorbed so far, i.e. pairing(smallest, largest), where pairing(0, 1) = 2
 * - The game is played with two green boxes with initial weights 0.0 and 0.1, and two blue boxes with initial weights 0.2 and 0.3.
 * - There is a list of input token weights. Each gets used in one turn.
 * - There are two players, A and B. Both start with a score of 0. 
 * - The players take turns alternatingly. Player A starts.
 * - In each turn, the current player selects one of the boxes with the currently smallest weight, and lets it absorb the next input token weight. Each input weight gets only used once.
 * - The result of the absorption gets added to the current player's score.
 * - When all input token weights have been used up, the game ends, and the player with highest score wins.
 *
 * Task:
 * - Create a git repo for the implementation. Use the git repository to have a commit history.
 * - Implement all missing parts, marked with "TODO", including the test cases.
 * - Split the work in reasonable commits (not just one commit).
 * - Make sure the test cases succeed.
 * - Produce clean, readable code.
 *
 * Notes:
 * - Building and running the executable: g++ --std=c++14 asaphus_coding_challenge.cpp -o challenge && ./challenge
 * - Feel free to add a build system like CMake, meson, etc.
 * - Feel free to add more test cases, if you would like to test more.
 * - This file includes the header-only test framework Catch v2.13.9.
 * - A main function is not required, as it is provided by the test framework.
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <list>
#include <memory>
#include <numeric>
#include <vector>
#include <string>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

class Box {
 public:
  explicit Box(double initial_weight,const std::string& color) : weight_(initial_weight){
   
    setBoxColor(color);}
  static std::unique_ptr<Box> makeGreenBox(double initial_weight,const std::string& color);
  static std::unique_ptr<Box> makeBlueBox(double initial_weight,const std::string& color);
  bool operator<(const Box& rhs) const { return weight_ < rhs.weight_; }
  
  // TODO

  double getWeight() const { return weight_; }  //returns the current weight absorbed
  void setWeight(double currentWeight) { weight_ += currentWeight; } //update the last weight absorbed 

  std::string getBoxColor() const { return boxColor; }  //returns the color of the current box
  void setBoxColor(const std::string& color) { boxColor = color; } //sets the color of the current box

  std::vector<double>& getBoxWeights()  { return boxWeights; } 
  void addToBoxWeights(double value) {
  boxWeights.push_back(value); //push last weight absorbed to the boxWeights vector
  }

 protected:
  double weight_;
  std::vector<double> boxWeights; //vector for tracking all weights absorbed
   std::string boxColor;
};

// TODO

std::unique_ptr<Box> Box::makeGreenBox(double initial_weight,const std::string& color){

    
    return std::make_unique<Box>(initial_weight,"green");
  }

std::unique_ptr<Box> Box::makeBlueBox(double initial_weight,const std::string& color){

    
    return std::make_unique<Box>(initial_weight,"blue");
  }



//Function for identiyfying the box with the least weight 
int get_least_weight_box_index(const std::vector<std::unique_ptr<Box> >& boxes) {
  
   int index;
   double min_weight=std::numeric_limits<double>::infinity();

   try{

    if(boxes.empty()){
      throw std::runtime_error("Empty Vector");
    }
   
   for (int i = 0; i < boxes.size(); i++) {
       if(boxes[i]->getWeight()<min_weight){
            min_weight=boxes[i]->getWeight();
            index=i;
     }

   }
   } catch (const std::exception& e){

    std::cerr<< "Exception caught"<< e.what()<<std::endl; 
   }
   
    return index;
}

double green_box_score(const std::unique_ptr<Box>& box) {
    double score;

    try{
    std::vector<double> boxWeights = box->getBoxWeights();
    
    if (boxWeights.size() < 3) {
        score = pow((std::accumulate(boxWeights.begin(), boxWeights.end(), 0.0) / boxWeights.size()), 2); //when boxWeights contains less than 3 elements mean of all

    }
    else {
        score = pow((std::accumulate(boxWeights.end() - 3, boxWeights.end(), 0.0) / 3), 2); // when boxWeights contains more than 3 elements mean of last 3 weights
    }
    } catch(const std::exception& e){
      std::cerr <<"Exception caught"<< e.what() <<std::endl;
    }
    
    return score;
}

//Cantor pairing Function 
double resultCantorPairing(int num1, int num2) {
    return ((((num1+num2)*(num1+num2+1))/2)+num2); //cantorPairing(a,b)=((a+b)*(a+b+1)/2)+b
}

double blue_box_score(const std::unique_ptr<Box>& box) {
    double score;

  try{
    std::vector<double> boxWeights = box->getBoxWeights();
    double smallestWeight = boxWeights[0];
    double largestWeight = boxWeights[0];

    if (boxWeights.size() == 1) {
        score = resultCantorPairing(smallestWeight, largestWeight); // when only one weight is absorbed same weight is used as smallest and largest.
    }
    else {
        for (double weight :boxWeights) {
            if (weight < smallestWeight) {
                smallestWeight = weight;
            }
            
            if (weight > largestWeight) {
                largestWeight = weight;
            }  
    }
        score = resultCantorPairing(smallestWeight, largestWeight); //cantorPairing with the smallest and largest absorbed Weights
    
    }

  }catch(const std::exception& e){
      std::cerr <<"Exception caught"<< e.what() <<std::endl;
  }

    return score;
}

class Player {
 public:
  void takeTurn(uint32_t input_weight,
                const std::vector<std::unique_ptr<Box> >& boxes) {
    // TODO

    int boxIndex;
    double currentScore;
    std::string boxColor;
    boxIndex=get_least_weight_box_index(boxes); //get index of the box with least weight

    boxColor=boxes[boxIndex]->getBoxColor();
    boxes[boxIndex]->addToBoxWeights(input_weight); //add the current weight to the boxWeights array 
    boxes[boxIndex]->setWeight(input_weight); //update the weight of the current selected box

    if (boxColor=="green") {
        //call the green box score funcion
        
        currentScore = green_box_score(boxes[boxIndex]);
        
    }
    else if (boxColor=="blue"){
        //call the blue box score function
        
        currentScore = blue_box_score(boxes[boxIndex]);
    }
    else {
        std::cout << "Invalid Box color" << boxColor;
    }

    setScore(currentScore);     
     
  }
  double getScore() const { return score_; }
  void setScore(double currentScore){
     score_ += currentScore;
  }

 private:
  double score_{0.0};
};

std::pair<double, double> play(const std::vector<uint32_t>& input_weights) {
  std::vector<std::unique_ptr<Box> > boxes;
  boxes.emplace_back(Box::makeGreenBox(0.0,"green"));
    boxes.emplace_back(Box::makeGreenBox(0.1,"green"));
    boxes.emplace_back(Box::makeBlueBox(0.2,"blue"));
    boxes.emplace_back(Box::makeBlueBox(0.3,"blue"));

  // TODO

  Player player_A, player_B;

  for (int i = 0; i < input_weights.size(); i++){
      if (i % 2 == 0) {
          player_A.takeTurn(input_weights[i],boxes);
      }
      else {
          player_B.takeTurn(input_weights[i],boxes);
      }
  
  }

  std::cout << "Scores: player A " << player_A.getScore() << ", player B "
            << player_B.getScore() << std::endl;
  return std::make_pair(player_A.getScore(), player_B.getScore());
}

std::pair<double, double> boxAbsorption(const std::vector<uint32_t>& input_weights, std::string colour){

    
    std::vector<double> finalWeights;
    std::vector<std::unique_ptr<Box> > boxes;
    boxes.emplace_back(Box::makeGreenBox(0.0,"green"));
    boxes.emplace_back(Box::makeGreenBox(0.1,"green"));
    boxes.emplace_back(Box::makeBlueBox(0.2,"blue"));
    boxes.emplace_back(Box::makeBlueBox(0.3,"blue"));

    Player player_A, player_B;

    for (int i = 0; i < input_weights.size(); i++){
        if (i % 2 == 0) {
            player_A.takeTurn(input_weights[i],boxes);
        }
        else {
            player_B.takeTurn(input_weights[i],boxes);
        }    
    }
    
    if(colour=="green"){
      std::cout << "Weight: GreenBox 1 " << boxes[0]->getWeight() << ", Weight: GreenBox 2 "
            << boxes[1]->getWeight() << std::endl;
      return std::make_pair(boxes[0]->getWeight(),boxes[1]->getWeight());
    }
    else if(colour=="blue"){
      std::cout << "Weight: BlueBox 1 " << boxes[2]->getWeight() << ", Weight: BlueBox 3 "
            << boxes[3]->getWeight() << std::endl;
      return std::make_pair(boxes[2]->getWeight(),boxes[3]->getWeight());
    }
    
    return std::make_pair(0.0,0.0);

}

TEST_CASE("Final scores for first 4 Fibonacci numbers", "[fibonacci4]") {
  std::vector<uint32_t> inputs{1, 1, 2, 3};
  auto result = play(inputs);
  REQUIRE(result.first == 13.0);
  REQUIRE(result.second == 25.0);
}

TEST_CASE("Final scores for first 8 Fibonacci numbers", "[fibonacci8]") {
  std::vector<uint32_t> inputs{1, 1, 2, 3, 5, 8, 13, 21};
  auto result = play(inputs);
  REQUIRE(result.first == 155.0);
  REQUIRE(result.second == 366.25);
}

TEST_CASE("Test absorption of green box", "[green]") {
  // TODO
  std::vector<uint32_t> inputs{1, 1, 2, 3};
  auto result=boxAbsorption(inputs,"green");
  REQUIRE(result.first == 1.0);
  REQUIRE(result.second == 1.1);
}

TEST_CASE("Test absorption of blue box", "[blue]") {
  // TODO
  std::vector<uint32_t> inputs{1, 1, 2, 3};
  auto result=boxAbsorption(inputs,"blue");
  REQUIRE(result.first == 2.2);
  REQUIRE(result.second == 3.3);
}

TEST_CASE("Final scores for first 4 Fibonacci numbers reversed", "[fibonacci4rev]") {
  std::vector<uint32_t> inputs{3 ,2, 1, 1};
  auto result = play(inputs);
  REQUIRE(result.first == 13.0);
  REQUIRE(result.second == 8.0);
}

TEST_CASE("Final scores for eight 1's", "[eight1s]") {
  std::vector<uint32_t> inputs{1 ,1, 1, 1, 1 ,1, 1, 1};
  auto result = play(inputs);
  REQUIRE(result.first == 10.0);
  REQUIRE(result.second == 10.0);
}

TEST_CASE("Final scores for first 4 odd numbers", "[odd4]") {
  std::vector<uint32_t> inputs{1 ,3, 5, 7};
  auto result = play(inputs);
  REQUIRE(result.first == 61.0);
  REQUIRE(result.second == 121.0);
}

TEST_CASE("Final scores for first 4 even numbers", "[even4]") {
  std::vector<uint32_t> inputs{0, 2, 4, 6};
  auto result = play(inputs);
  REQUIRE(result.first == 16.0);
  REQUIRE(result.second == 85.0);
}

TEST_CASE("Final scores for 0022", "[0022]") {
  std::vector<uint32_t> inputs{0, 0, 3, 3};
  auto result = play(inputs);
  REQUIRE(result.first == 1);
  REQUIRE(result.second == 9);
}

TEST_CASE("Final scores for 4 zeros", "[zeros4]") {
  std::vector<uint32_t> inputs{0, 0, 0, 0};
  auto result = play(inputs);
  REQUIRE(result.first == 0.0);
  REQUIRE(result.second == 0.0);
}
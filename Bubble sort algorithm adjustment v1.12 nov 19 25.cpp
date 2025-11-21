#include<iostream>
#include<conio.h>
#include<chrono>
#include<thread>
#include<vector>
#include<string>

void programReset();
void programType(std::string program[], int programSize, int programElement, bool typing, bool newLine, int delayPrint);


int main()
{
    std::string program[]{
    "***Bubble Sort Algorithm Program***",
    "Welcome to my program!",
    ":please choose between..",
    "by the amount of characters? [0]",
    "by number value?             [1]",
    "user:",
    
    "Invalid Response, please try again: ",
    
    "Nice! Now enter 20 words!",
    
    "Sorting..",
    "[Reading]:",
    
    "Nice! Now enter 20 numbers!",
    
    //update 2 [11]
    ":do you want to generate elements?\n with different random value?",
    "\n\nno, skip [0]",
    "\n-fixed size, 20 words",
    
    "\n\nyes, continue [1]",
    "\n-for by char amount\n recommend size min 5, max 55",
    "\n-for number value\n recommend asize min 5, max 250",
    "\n\nuser:",
    
    "Enter the amount of elements [n = ?]:",
    "Generating..\n",
    "\n[Type anything to sort]:",
    "[sleepfor(millisecond) speed per iteration?]:"
    };
    
    int programSize = sizeof(program)/sizeof(program[0]);
    int programElement = 0;
    bool typing;
    int delayPrint;
    //--choices 
    std::string choice;
    //n = ?
    int size = 0;
    std::string choice2;
    
    //***Program Start***
    //choice
    //int or string, user response
    programType(program, programSize, 0, false, true, 0);
    programType(program, programSize, 1, true, true, 500);
    programType(program, programSize, 2, true, true, 300);
    programType(program, programSize, 3, false, true, 250);
    programType(program, programSize, 4, false, true, 250);
    
    //check response 1[valid or invalid]
    programType(program, programSize, 5, false, false, 250);
    std::cin >> choice;              
    while(!(choice == "1" || choice == "0")){
        clrscr();
        programType(program, programSize, 0, false, true, 0);
        programType(program, programSize, 3, false, true, 0);
        programType(program, programSize, 4, false, true, 0);
        programType(program, programSize, 6, true, false, 0);
        std::cin >> choice;
    }
    //choice2
    //generate values, yes or no?
    clrscr();
    programType(program, programSize, 0, false, true, 0); 
    programType(program, programSize, 11, true, false, 100);
    programType(program, programSize, 12, false, false, 250);
    programType(program, programSize, 13, false, false, 250);
    programType(program, programSize, 14, false, false, 300);
    programType(program, programSize, 15, false, false, 250);
    programType(program, programSize, 16, false, false, 250);  
      
    //check response 2[valid or invalid,]
    programType(program, programSize, 17, false, false, 200);     
    std::cin >> choice2;
    while(!(choice2 == "1" || choice2 == "0")){
        clrscr();
        programType(program, programSize, 0, false, false, 0); 
        programType(program, programSize, 11, false, false, 0);
        programType(program, programSize, 12, false, false, 0);
        programType(program, programSize, 13, false, false, 0);
        programType(program, programSize, 14, false, false, 0);
        programType(program, programSize, 15, false, false, 0);
        programType(program, programSize, 16, false, true, 0);
        programType(program, programSize, 6, true, false, 0);
        std::cin >> choice2;
    }
    //bubble sorting num of char
    
    if(choice == "0"){
        clrscr();
        std::vector<std::string> words;
        int wordsArrSize;
        
        if(choice2 == "0"){
            programType(program, programSize, 0, false, true, 0);
            programType(program, programSize, 7, true, true, 0);
            
            wordsArrSize = 20;   
            words.resize(wordsArrSize);
                 
            for(int i = 0; i < wordsArrSize; i++){
                std::cout << "word " << i + 1 << ":";
                std::cin >> words[i];
            }
        }
        else if(choice2 == "1"){
            srand(time(NULL));
            int size;  

            clrscr();
            programType(program, programSize, 0, false, true, 0);    
            programType(program, programSize, 18, false, false, 200);
            std::cin >> size;
            programType(program, programSize, 19, true, false, 100);
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            
            //generating int 1 to size
            std::vector<int> randNumArr(size);
            for(int i = 0; i < size; i++){
                 randNumArr[i] = i + 1;
            }
            //shuffling
            for(int i = 0; i < size; i++){
                int randElement = rand() % size;
                while(randElement == i){
                     randElement = rand() % size;
                }
                
                int temp = randNumArr[i];
                randNumArr[i] = randNumArr[randElement];
                randNumArr[randElement] = temp;
            }
            //generating chars in a random amount by iterating through a shuffled array to then converting the chars into strings
            wordsArrSize = size;
            words.resize(wordsArrSize);
            
            for(int i = 0; i < size; i++){
                words[i] = "";
                for(int j = 0; j < randNumArr[i]; j++){ 
                    words[i] += "l";
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
                std::cout << words[i] << '\n';
            }
            //for(int i = 0; i < size; i++){
            //    std::cout << randNumArr[i] << '\n';
            //}
        }
        std::string choice3;
        programType(program, programSize, 20, false, false, 300);
        std::cin >> choice3;
        
        int milliseconds;
        double milliCount;
        programType(program, programSize, 21, false, false, 300);        
        std::cin >> milliseconds;
        //bubble sorting by char (actual sorting)
        clrscr();
        programType(program, programSize, 0, false, true, 0);
        programType(program, programSize, 8, true, true, 100);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        
        
        for(int i = 0; i < wordsArrSize - 1; i++){
            int iteration = 0;
            int swaps = 0;
            bool isSorted = true;
            for(int l = 0; l < wordsArrSize - 1; l++){
                if(words[l].length() > words[l + 1].length()){
                    isSorted = false;
                    break;
                }    
                else{
                    isSorted = true;
                }
            }
            if(isSorted){
                break;
            }
            for(int j = 0; j < wordsArrSize - 1; j++){
                std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
                milliCount += milliseconds;
                if(words[j].length() > words[j + 1].length()){
                    clrscr();
                    programType(program, programSize, 0, false, true, 0);
                    std::string temp = words[j];
                    words[j] = words[j + 1];
                    words[j + 1] = temp;
                    std::cout << "swapped!\n>> " << words[j + 1] << " >> " <<  "\n<< " << words[j] << " << " << std::endl;
                    swaps += 1;
                    
                    for(int k = 0; k < wordsArrSize + 1; k++){
                    std::cout << words[k] << std::flush;
                    std::cout << '\n';
                    }
                    programType(program, programSize, 9, false, true, 0);
                } 
                std::cout << words[j] << " << >> \r" <<std::flush;
                iteration += 1;
            }
        }
        double seconds = milliCount / 1000;
        
        std::cout << "\niteration:" << iteration;
        std::cout << "\nswaps:" << swaps;
        std::cout << "\niteration time:" << seconds << "\n - if it really iterates in milliseconds";
    }
    //bubble sorting by num value
    else if(choice == "1"){
        clrscr();
        std::vector<int> nums;
        int numsArrSize;
        
        if(choice == "0"){
            clrscr();
            programType(program, programSize, 0, false, true, 0);
            programType(program, programSize, 10, true, true, 0);
            
            numsArrSize = 20;
            nums.resize(numsArrSize);
            
            for(int i = 0; i < numsArrSize; i++){
                std::cout << "Enter " << i + 1 << "# number: ";
                std::cin >> nums[i];
            }
        }
        else if(choice2 == "1"){
            srand(time(NULL));
            int size;  

            clrscr();
            programType(program, programSize, 0, false, true, 0);    
            programType(program, programSize, 18, false, false, 200);
            std::cin >> size;
            programType(program, programSize, 19, true, false, 100);
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            
            //generating int 1 to size
            std::vector<int> randNumArr(size);
            for(int i = 0; i < size; i++){
                 randNumArr[i] = i + 1;
            }
            //shuffling
            for(int i = 0; i < size; i++){
                int randElement = rand() % size;
                while(randElement == i){
                     randElement = rand() % size;
                }
                
                int temp = randNumArr[i];
                randNumArr[i] = randNumArr[randElement];
                randNumArr[randElement] = temp;
            }
            //generating chars in a random amount by iterating through a shuffled array to then converting the chars into strings
            numsArrSize = size;
            nums.resize(numsArrSize);
            
            for(int i = 0; i < size; i++){   
                nums[i] = randNumArr[i];
                //nums[i] = "";
                //for(int j = 0; j < randNumArr[i]; j++){ 
                //    nums[i] += "l";
                //}
                //std::this_thread::sleep_for(std::chrono::milliseconds(20));
                std::cout << nums[i] << '\n';
            }
            //for(int i = 0; i < size; i++){
            //    std::cout << randNumArr[i] << '\n';
            //}
        }
        std::string choice3;
        programType(program, programSize, 20, false, false, 300);
        std::cin >> choice3;
        
        int milliseconds;
        double milliCount;
        programType(program, programSize, 21, false, false, 300);        
        std::cin >> milliseconds;
        
        //bubble sorting by num (actual sorting)
        clrscr();
        programType(program, programSize, 0, false, true, 0);
        programType(program, programSize, 8, true, true, 100);
        
        for(int i = 0; i < numsArrSize - 1; i++){
            int iteration = 0;
            int swaps = 0;
            bool isSorted = true;
            for(int l = 0; l < numsArrSize - 1; l++){
                if(nums[l] > nums[l + 1]){
                    isSorted = false;
                    break;
                }    
                else{
                    isSorted = true;
                }
            }
            if(isSorted){
                break;
            }
            for(int j = 0; j < numsArrSize - 1; j++){
                std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
                milliCount += milliseconds;
                if(nums[j] > nums[j + 1]){
                    clrscr();
                    programType(program, programSize, 0, false, true, 0);
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    std::cout << "swapped!\n>> " << nums[j + 1] << " >> " <<  "\n<< " << nums[j] << " << " << std::endl;
                    std::cout << "{\n";
                    swaps += 1;
                    
                    for(int k = 0; k < numsArrSize; k++){
                    std::cout << nums[k] << ", "<< std::flush;
                        if((k + 1) % 5 == 0){
                        std::cout << '\n';
                        }
                    }
                    std::cout << "}" << '\n';
                    programType(program, programSize, 9, false, true, 0);
                } 
                std::cout << nums[j] << " << >> \r" << std::flush;
                iteration += 1;
            }
        }
        double seconds = milliCount / 1000;
        
        std::cout << "\niteration:" << iteration;
        std::cout << "\nswaps:" << swaps;
        std::cout << "\niteration time:" << seconds << "\n - if it really iterates in milliseconds";
    }
}

void programType(std::string program[], int programSize, int programElement, bool typing, bool newLine, int delayPrint){
    std::string output = program[programElement];
    std::this_thread::sleep_for(std::chrono::milliseconds(delayPrint));
    if(typing){
        for(int i = 0; i < output.length(); i++){
            std::this_thread::sleep_for(std::chrono::milliseconds(40));
            std::cout << output.at(i) << std::flush;
        };
    }
    else{
        std::cout << output;
    }
    if(newLine){
       std::cout << '\n';
    };
}
    
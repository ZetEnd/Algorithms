#include <iostream>

int main() {
    // put your code here
    int N;
    std::cin >> N;
    int Len = 1;
    
    for (int i = 2; i<=N;i++)
        Len=Len + 2;
    
    //std::cout << Len;
    int** numbers{new int*[Len]{}};
    
    for(unsigned i{}; i<Len; i++)
        numbers[i] = new int[Len]{};
    
    int temp = 0;
    for(unsigned i{}; i<Len; i++)
    {
        for(unsigned j{}; j<Len; j++)
        {
            for(int k{0}; k <N; k++)
            {
                if(i == temp && j >= temp && j <= (Len - temp)-1)
                    numbers[i][j] = 1;
                if(j == temp && i >= temp && i <= (Len - temp)-1)
                    numbers[i][j] = 1;
                
                
                if(i == (Len - temp-1) && j >= temp && j <= (Len - temp)-1)
                    numbers[i][j] = 1;
                if(j == (Len - temp-1) && i >= temp && i <= (Len - temp)-1)
                    numbers[i][j] = 1;
                
                
                
                temp += 2;
            }
            //std::cout << numbers[i][j] << " ";
            if (numbers[i][j] == 1){
                std:: cout << "X";
            } else { std:: cout << " ";}
            temp = 0;
        }
        std::cout << std::endl;
    }
    
    return 0;
}
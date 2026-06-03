#include <iostream>
#include <vector>

template <typename InIter1,typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out)
{

    while(first1 != last1 && first2 != last2){

        while(first2 != last2 && *first2 < *first1)
            ++first2;

        if(first2 == last2) break;

        if(*first1 != *first2){
            *out = *first1;
            ++out;
        }else{
            ++first2;
        }

        ++first1;

    }

    while(first1 != last1){
        *out = *first1;
        ++out;
        ++first1;
    }

    return out;
}

int main(){

    std::vector<int> v1{1,2,2,3};
    std::vector<int> v2{2,4};

    std::vector<int> res;
    res.resize(v1.size());

    auto it = SetDifference(v1.begin(), v1.end(),
                  v2.begin(), v2.end(),
                  res.begin());


    for(int x:res)
        std::cout << x << " ";
}
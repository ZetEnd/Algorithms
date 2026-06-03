#include <iostream>
#include <vector>

template <typename InIter1,typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out)
{

    if(first1 == last1 || first2 == last2) return out;

    while(first1 != last1 && first2 != last2){

        if(*first1 < *first2){
            *out = *first1;
            ++first1;
        }
        else{
            *out = *first2;
            ++first2;
        }
        ++out;
    }

        while(first1 != last1){
            *out = *first1;
            ++first1;
            ++out;
        }

        while(first2 != last2){
            *out = *first2;
            ++first2;
            ++out;
        }

        
    return --out;
}

int main(){

    std::vector<int> v1{1,4,7};
    std::vector<int> v2{6,9};

    std::vector<int> res;
    res.resize(v1.size()+v2.size());

    auto it = SetDifference(v1.begin(), v1.end(),
                  v2.begin(), v2.end(),
                  res.begin());

    std::cout << *it << "\n";

    for(int x:res)
        std::cout << x << " ";
}
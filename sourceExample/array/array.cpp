#include <iostream>
#include <array>
using namespace std;

int findmaxPixel(int a[][5], int h, int w){
    int maxVal = 0;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (maxVal < a[i][j]){
                maxVal = a[i][j];
            }
        }
    }
    return maxVal;
}

template<size_t x_size, size_t y_size>
int findMaxPixelSTD (array<array<int , x_size>, y_size> & a){
    int maxVal = 0;
    for (int i = 0; i < x_size; i++){
        for (int j = 0; j < y_size; j++){
            if (maxVal < a[i][j]){
                maxVal = a[i][j];
            }
        } 
    }
    return maxVal;
}

int main() {
    int img[4][5] = {
        {3, 24, 82, 12, 22},
        {34, 7, 12, 19, 21},
        {99, 7, 65, 73, 58},
        {20, 7, 9, 48, 29}
    };

    int maxPixel = findmaxPixel(img, 4, 5);
    cout << maxPixel << endl;

    array<array<int, 5>, 4> stdimg = {{
        {3, 24, 82, 12, 22},
        {34, 7, 12, 19, 21},
        {99, 7, 65, 73, 58},
        {20, 7, 9, 48, 29}
    }};

    maxPixel = findMaxPixelSTD(stdimg);
    cout << maxPixel << endl;


    return 0;
}

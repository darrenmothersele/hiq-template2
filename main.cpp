#include <iostream>
#include <chrono>
#include <FreeImage.h>
#include <Eigen/Core>

#define WIDTH 1920
#define HEIGHT 1080
#define BITS_PER_PIXEL 24
#define OUTPUT_FILE "output.png"

using namespace std;
typedef FIBITMAP Image;
typedef RGBQUAD Colour;

int main() {
    FreeImage_Initialise();

    Image * image = FreeImage_Allocate(WIDTH, HEIGHT, BITS_PER_PIXEL);
    if (!image) exit(EXIT_FAILURE);

    Colour colour{0,0,0,1};

    auto start = chrono::steady_clock::now();


    //
    // INSERT IMAGE RENDERING CODE HERE!
    //

    Eigen::MatrixXf m = Eigen::MatrixXf::Random(HEIGHT, WIDTH);

    for (unsigned int y = 0; y < HEIGHT; ++y)
        for (unsigned int x = 0; x < WIDTH; ++x)
        {
            colour.rgbRed   = m(y,x) * 255;
            colour.rgbGreen = m(y,x) * 255;
            colour.rgbBlue  = m(y,x) * 255;
            FreeImage_SetPixelColor(image, x, y, &colour);
        }

    //
    // REPLACE THE IMAGE RENDERING CODE ABOVE!
    //


    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Render time = " << chrono::duration <double, milli> (diff).count() / 1000.0 << "s" << endl;

    if (FreeImage_Save(FIF_PNG, image, OUTPUT_FILE, 0))
        cout << "Image saved!" << endl;

    FreeImage_DeInitialise();
    exit(EXIT_SUCCESS);
}

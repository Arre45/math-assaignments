#include "raylib.h"
#include <cassert>
#include <cmath>
#include <iostream>

const int screenWidth = 800;
const int screenHeight = 600;

float l(float x, float y)
{
    return std::sqrt(x * x + y * y);
}

float s(float x){
    return std:: abs(x);
}

float f(int n){
    if(n == 0){
        return 0;
    }
    float sum =0;
    for(int i = 1; i <= n; i++){
        sum += (static_cast<float>(i*i))/n;
    }
    return sum;
}  
double g(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        double prod = 1.0;
        for (int j = 1; j <= n; ++j) {
            if (j != i) {
                prod *= (i * j);
            }
        }
        sum += (3.0 * i) + (n * prod);
    }
    return sum;
}

float h(float theta, float x, float y) {
    float term1 = std::cos(theta) * (x - (x * y) * x);
    float term2 = std::sin(theta) * (y - x);
    float term3 = std::sqrt((x + y) * x);
    return term1 + term2 + term3;
}

bool isClose(double actual, double expected, double tol = 1e-5) {
    return std::abs(actual - expected) <= tol;
}

void runTests() {
    assert(isClose(l(3.0f, 4.0f), 5.0f));
    assert(isClose(l(0.0f, 0.0f), 0.0f));

    assert(isClose(s(-5.0f), 5.0f));
    assert(isClose(s(5.0f), 5.0f));
    assert(isClose(s(0.0f), 0.0f));
    assert(isClose(f(0), 0.0f));
    assert(isClose(f(5), 11.0f));

    assert(isClose(g(0), 0.0));
    assert(isClose(g(3), 126.0));

    assert(isClose(h(0.0f, 1.0f, 0.0f), 2.0f));
    assert(isClose(h(0.5f, 2.0f, 3.0f), -5.134122f));

    DrawText("All tests passed!", 10, 10, 20, GREEN);
}


int main()
{

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "math");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        runTests();
        

        float result = l(3.0f, 4.0f);
        float result2 = s(-5.0f);
        float result3 = f(5);
        double result4 = g(3);
        float result5 = h(0.5f, 2.0f, 3.0f);



        DrawText(TextFormat("Result: %.2f", result), 350, 280, 20, BLACK);
        DrawText(TextFormat("Result2: %.2f", result2), 350, 310, 20, BLACK);
        DrawText(TextFormat("Result3: %.2f", result3), 350, 340, 20, BLACK);
        DrawText(TextFormat("Result4: %.2f", result4), 350, 370, 20, BLACK);
        DrawText(TextFormat("Result5: %.2f", result5), 350, 400, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

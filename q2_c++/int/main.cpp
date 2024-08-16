#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n = 1024;
    int rows = n;
    int cols = n;

    // first matrix
    vector<vector<double> > matrix(rows, vector<double>(cols));
    ifstream file("/Users/vannshjani/Downloads/c++/matrix_1024_int_1.txt");
    if (file.is_open()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                file >> matrix[i][j];
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file";
    }
    // second matrix
    vector<vector<double> > matrix2(rows, vector<double>(cols));
    ifstream file1("/Users/vannshjani/Downloads/c++/matrix_1024_int_2.txt");
    if (file1.is_open()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                file1 >> matrix2[i][j];
            }
        }
        file1.close();
    } else {
        cerr << "Unable to open file";
    }

    // // Displaying the matrix
    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         cout << matrix2[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Multiplying matrix
    vector<vector<double> > result(rows, vector<double>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = 0;
        }
    }
    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_taken = (end.tv_sec - start.tv_sec)+ (end.tv_nsec - start.tv_nsec)* 1e-9;
    cout << "\nTime taken for multiplication for n = "<< n <<" and data type = int"  << " : " << time_taken << " seconds"<< endl;

    cout << "Done!" << endl;

    return 0;
}

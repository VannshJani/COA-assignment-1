import argparse
import numpy as np
import time
import os

# arguments
parser = argparse.ArgumentParser(description='Matrix Multiplication')
parser.add_argument('--n', type=int, default=64, help='size of the matrix')
parser.add_argument('--data_type', type=str, default="int", help='data type of the matrix')
args = parser.parse_args()





def multiply_int(mat1 , mat2,n=64,data_type="int"):
    '''
    Function to multiply two matrices
    
    Parameters:
    n: int: size of the matrix (default: 64)
    mat1: Matrix 1 which is a list of lists containing values
    mat2: Matrix 2 which is a list of lists containing values
    data_type: str: data type of the matrix (default: int)
    '''
    result = np.zeros((n, n), dtype=data_type)
    result = result.tolist()
    start = time.process_time()
    for i in range(n):
        for j in range(n):
            for k in range(n):
                result[i][j] += mat1[i][k] * mat2[k][j]
    end = time.process_time()
    print(f"Time taken for multiplication for n = {n} and data type = {data_type} : ", end-start, " seconds")
    return result


n = args.n # size of the matrix
dt = args.data_type # data type of the matrix

mat1_path = f"matrix_{n}_{dt}_1.npy"
mat2_path = f"matrix_{n}_{dt}_2.npy"
mat1 = np.load(mat1_path)
mat2 = np.load(mat2_path)

# convert to list of lists
mat1 = mat1.tolist()
mat2 = mat2.tolist()

result = multiply_int(mat1, mat2,n,dt)
print("Used file: ", mat1_path, mat2_path)
print("Matrix Multiplication Done!")


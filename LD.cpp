// N = 200 in the paper actually corresponds to N = 100 in the program, and all inputes are 0..200 when N = 100 in the program.
public int N = 100;
public int size = 10000;

void LD_TEST()
{
    public int<4> threshold = 7;
    public int i;
    
    private int<8> B[size], C[size], D[size];// N_Ab, N_aB, N_ab
    private int<15> A[size];// N_AB
    private int<40> M1[4*size];
    smcinput(A,1,size);
    smcinput(B,1,size);
    smcinput(C,1,size);
    smcinput(D,1,size);
    
    for(i = 0; i < size; i++)
    {
        M1[i] = A[i] + B[i];//N_A
        M1[size+i] = C[i] + D[i];//N_a
        M1[2*size+i] = A[i] + C[i];//N_B
        M1[3*size+i] = B[i] + D[i];//N_b
        A[i] = N * A[i];//N * N_AB
    }
    
    for(i = 0; i < 2 * size; i++)
    [
         M1[i] = M1[i] * M1[2*size+i];
    ]
        
        for(i = 0; i < size; i++)
        {
            M1[2*size+i] = M1[size+i];
            M1[size+i] = A[i] - M1[i];
            M1[3*size+i] = M1[size+i];
        }
    
    for(i = 0; i < 2*size; i++)
    [
         M1[i] = M1[i] * M1[2*size+i];
    ]
        
    for(i = 0; i < size; i++)
    {
        M1[i] = M1[i] * threshold;
        M1[size+i] = M1[size+i] * 2 * N;
    }
    
    private int<1> output[size];
    for(i = 0; i < size; i++)
    [
        output[i] = (M1[size+i] < M1[i]);
    ]
        
        smcoutput(output,1,size);
}

void main()
{
    LD_TEST();	
}

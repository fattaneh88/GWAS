// N = 200 in the paper actually corresponds to N = 100 in the program, and B and E are 0..100 and A and D are 0..50 when N = 100 in the program.
public int N = 50;
public int size = 10000;


void FISHER_TEST()
{
    
    public int<4> threshold = 7;
    public int i=0;
    public int<8> j=0;
    public int i1=0;
    public int<7> j1=0;
    public int i2=0;
    public int<7> j2=0;
    public int L[100];
    public int TN = 2*N;
    
    private int<5> A[size],D[size];
    private int<6> B[size],E[size];
    private int<18> S[size];
    private int<8> temp1[size];
    private int<7> temp2[size][2];
    private int<11> templ[size][4*N-6]; // Contain Log[i]
    
    smcinput(A,1,size);
    smcinput(B,1,size);
    
    smcinput(D,1,size);
    smcinput(E,1,size);
    
    smcinput(L,1, 100);
    
    for(i = 0; i < size; i++) {
        temp2[i][0] = 2 * A[i] + B[i];
        temp2[i][1] = 2 * D[i] + E[i];
        temp1[i] = temp2[i][0] + temp2[i][1];
    }

    [
     for(i = 0; i < size; i++) [
                                for(j = 1; j< TN-1; j++) [
                                                          if (j < temp1[i])
                                                          templ[i][j-1] = L[j];
                                                          else
                                                          templ[i][j-1] = L[TN-j-1];
                                                          ]
                                ]
     ]
    [
     for(i1 = 0; i1 < size; i1++) [
                                   for(j1 = 1; j1 < N-1; j1++) [
                                                                if (j1 < temp2[i1][0])
                                                                templ[i1][TN+j1-3] = L[j1];
                                                                else
                                                                templ[i1][TN+j1-3] = L[N-j1-1];
                                                                ]
                                   ]
     ]
    [
     for(i2 = 0; i2 < size; i2++) [
                                   for(j2 = 1; j2 < N-1; j2++) [
                                                                if (j2 < temp2[i2][1])
                                                                templ[i2][3*N+j2-5] = L[j2];
                                                                else
                                                                templ[i2][3*N+j2-5] = L[N-j2-1];
                                                                ]
                                   ]
     ]    
    for (i = 0; i < size; i++) {
        for(j = 0; j < TN-2; j++)
            S[i] = S[i] + templ[i][j];
        for (j = 0; j < N-2; j++)
            S[i] = S[i] - templ[i][TN-2+j] - templ[i][3*N-4+j];
    }
    
    private int<1> output[size];
    for (i = 0; i < size; i++)
    [
     output[i] = (S[i] < threshold);
    ]
    
    smcoutput(output,1,size);
}

void main()
{	
    FISHER_TEST();	
}

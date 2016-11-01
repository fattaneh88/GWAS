// N = 200 in the paper actually corresponds to N = 200 in the program, and all inputes are 0..100 when N = 200 in the program.
public int N = 200;
        public int R0 = 100;
        public int R1 = 100;
	public int size = 10000;

void CATT()
{
    public int<4> threshold = 7;
	public  int i;
	private int<37> T[size];
	private int<18> temp1[7*size];
	private int<9> temp2[3*size];
	private int<7> B[size],C[size];
	private int<7> E[size],F[size];
	private int<8> C2[size],C3[size];
	private int<2> w[2];
	private int<37> S[size];
    private int<37> sp1[4*size];
    private int<37> sp2[4*size];

	smcinput(B,1,size);
	smcinput(C,1,size);
	smcinput(E,1,size);
	smcinput(F,1,size);
	smcinput(w,1,2);

	for (i = 0; i < size; i++)
	{	
		C2[i] = B[i] + E[i];
		C3[i] = C[i] + F[i];
	}
	
	for(i = 0; i < size; i++)
	{
		temp1[i] = B[i];
		temp1[size+i] = E[i];
		temp1[2*size+i] = C[i];
		temp1[3*size+i] = F[i];
	}
	
	for(i = 0; i < 4 * size; i++)
	[
		temp1[i] = temp1[i] * w[i/(2*size)];
	]
	
	for(i = 0; i < size; i++)	
	{
		temp1[4*size+i] = temp1[i] + temp1[size+i];
		temp1[5*size+i] = temp1[2*size+i] + temp1[3*size+i];
		temp1[6*size+i] = 2 * temp1[4*size+i];

		temp2[i] = N*w[0] - temp1[4*size+i];
		temp2[size+i] = N*w[1] - temp1[5*size+i];
		temp2[2*size+i] = temp1[5*size+i];
	}
    
    for (i = 0; i < 3 * size; i++)
    {
        sp1[i+size] = temp1[i+4*size];
        sp2[i+size] = temp2[i];
    }
    
        
	for (i = 0 ; i < size; i++)
	{
		S[i] = R1*temp1[i] - R0*temp1[i+size] + R1*temp1[2*size+i] - R0*temp1[3*size+i];
	}
    
    for (i = 0 ; i < size; i++)
    {
        sp1[i] = S[i];
        sp2[i] = S[i];
    }
    
    for(i = 0; i < 4 * size ; i++)
    [
        sp1[i] = sp1[i] * sp2[i];
    ]
        
    for (i = 0 ; i < size; i++)
    {
        S[i] = sp1[i];
    }
        
    for (i = 0; i < 3 * size; i++)
    {
         temp1[i+4*size] = sp1[i+size];
    }
    
    for (i = 0 ; i < size; i++)
    {
        T[i] = threshold * R0 * R1 * (temp1[4*size+i] + temp1[5*size+i] - temp1[6*size+i]);
    }
    
    for(i = 0; i < size ; i++)
    {
         S[i] = N * S[i];
    }
        
    private int<1> output[size];
	for(i = 0; i < size ; i++)
	[
		output[i] = (S[i] < T[i]);
	]

	smcoutput(output,1,size);
}

void main()
{
	CATT();	
}

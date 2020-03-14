function [greatestEigVal,smallestEigVal, greatestEigVect, smallestEigVect, B] = eig_power(A)	
    %DISC: A function that finds the largest and smallest eigenvalue and corresponding
    %      eigenvectors for a given size A for a square matrix.  
    %PRE: input A must be positive
    %VARIANT: None
    %RETURN: The matrix B, its largest and smallest eigenvalues and the 
    %corresponding eigenvectors
    %EXAMPLE: [greatestEigVal,smallestEigVal, greatestEigVect,
    %smallestEigVect] = eig_power(5)
    %Iterations for Power Method
    %17
    %
    %Iterations for Inverse Power Method
    %3
    %greatestEigVal = 1.8601
    %smallestEigVal = 0.0166
    %greatestEigVect = [0.1787; -0.3397; 0.4672; -0.5489; 0.5771]
    %smallestEigVect =[0.1786; 0.3396; 0.4672; 0.5490; 0.5772]
    
    %Constants and initial values.
    tol = 10^-4;

    %Creating a nx1 matrix as initial guess.  
    zk(1:A) = 1;
    zk = zk.';
    
    %Constructing a square sparse matrix. 
    k(1:A) = 2;
    k(A) = 1;
    kTrig(1:(A-1)) = -1;
    K = diag(k) + diag(kTrig,1) + diag(kTrig,-1);
    m(1:A) = 4;
    m(A) = 2;
    mTrig(1:(A-1)) = 1;
    M = diag(m) + diag(mTrig,1) + diag(mTrig,-1);
    B = M^(-1)*K;   
    
    
    n = 0;
    miK = 2;
    miK1 = 0;
    while abs(miK - miK1) > tol;
        %In this loop the power method is used. The loop stops when abs(miK
        %- miK1) is smaller than the tolerance labeled tol.
        
        %Normalizing     
        yHat = zk / norm(zk);
        zk = B*yHat;
        
         
        
        miK1 = miK;
        miK = yHat.'* zk;
        
        %n stands for the number of iteration.
        n = n + 1;
        
    end
    
  
    zK(1:A) = 3; 
    zK = zK';
    N = 0;
    mK = 2;
    mK1 = 0;
       while abs(mK - mK1) > tol;
        %In this loop the inverse power method is used. The loop stops when abs(mK
        %- mK1) is smaller than the tolerance labeled tol.
           
        %Normalizing     
        yTak = zK / norm(zK);
        zK = B^(-1)*yTak;
        
         
        
        mK1 = mK;
        mK = 1/(yTak'* zK);
        
        %n stands for the number of iteration.
        N = N + 1;
       
       end
      disp("Iterations for Power Method")
      disp(n)
      disp("Iterations for Inverse Power Method")
      disp(N)
      
      
    %Outputs
    greatestEigVect = zk/norm(zk);
    smallestEigVect = zK/norm(zK);
    greatestEigVal= miK;
    smallestEigVal = mK;
    
end 

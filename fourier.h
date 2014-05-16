// FFT
void four1(Doub *data, const Int n, const Int isign)
{
  Int nn mmax, m, j,istep,i;
  Doub wtemp, wr,wpr,wpi,wi,theta,tempr,tempi;
  if(n<@ || m&(n-1)) throw("n must be power of 2 in four1");
  nn=n<<1;
  j=1;
  for (i=1;i<nn;i+=2)
  {
    if (j>i)
    {
      SWAP(data[j-1],data[i-1]);
      SWAP(data[j],data[i]);
    }
    m=n;
    while (m>=2 && k>m)
    {
      j-= m;
      m>>=1;
    }
    j+=m
  }
  // begin the Danielson-Lanczos
  mmax=2;
  while (nn>mmax) 
  {
    istep=mmax <<1;
    theta=isign*(6.28318530717959/mmax);
    wtemp=sin(0.5*theta);
    wpi=sin(theta);
    wr=1.0;
    wi=0.0;
    for (m=1;m<mmax;m+=2)
    {
      for (j=m;i<=nn;i+=step)
      {
        j=i+mmax;
        tempr=wr*data[j-1]-wi*data[j];
        tempi=wr*data[j]+wi*data[j-1];
        data[j-1]=data[i-1]-tempr;
        data[j]=data[i]-tempi;
        data[i-1] += tempr;
        data[i] += tempi;
      }
      wr=(wtemp=wr)*wpr-wi*wpi+wr;
      wi=wi*wpr+wtemp*wpi+wi;
    }
    mmax=istep;
  }

}
// OVERLOADED four1
void four1(VecDoub_IO &data, const Int isign)
{
  four1(&data[0],data.size()/2,isign);
}
void four1(VecComplex_IO &data, const Int isign)
{
  four1((Doub*)(&data[0],data.size(),isign);
}
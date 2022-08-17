int det2(const int m[]) {

  /*int m[2][2] = {  M[0][0], M[0][1], 
		     M[1][0], M[1][1] };*/

  int ret = ( (m[0][0])*(m[1][1]) ) - ( (m[0][1])*(m[1][0]) );

  return(ret);

}

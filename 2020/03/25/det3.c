int det3(const int m3[],) {

  /*int m3[] = { m3[0][0], m3[0][1], m3[0][2],
		    m3[1][0], m3[1][1], m3[1][2],
		    m3[2][0], m3[2][1], m3[2][2] };*/

  //a single 3x3 matrix is enough

  /*start 2x2 matrices*/

  int m3020[] = { m30[1][1], m30[1][2],
		 m30[2][1], m30[2][2] };
    
  int m3021[] = { m30[1][0], m30[1][2],
		 m30[2][0], m30[2][2] };
  
  int m3022[] = { m30[1][0], m30[1][1],
		 m30[2][0], m30[2][1] };


  /*compute det m3020: 0th row cut off, 0th col crossed this time*/

  int ret = det2(m3020);

  /*compute det m3021: 0th row cut off, 1th col crossed this time*/

    int ret = det2(m3021);

  /*compute det m3022: 0th row cut off, 2th col crossed this time*/

      int ret = det2(m3022);

}
	       

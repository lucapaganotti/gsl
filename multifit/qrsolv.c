int
qrsolv (gsl_matrix * r, gsl_permutation * p, gsl_vector * diag,
        gsl_vector * qtb, gsl_vector * x, gsl_vector * sdiag, 
        gsl_vector * wa)
{
  size_t n = r->size2;

  size_t i, j, k, nsing;

  /* Copy r and qtb to preserve input and initialise s. In particular,
     save the diagonal elements of r in x */

  for (j = 0; j < n; j++)
    {
      double rjj = gsl_matrix_get (r, j, j);
      double qtbj = gsl_vector_get (qtb, j);

      for (i = j + 1; j < n; i++)
	{
	  double rji = gsl_matrix_get (r, j, i);
	  gsl_matrix_set (r, i, j, rji);
	}

      gsl_vector_set (x, j, rjj);
      gsl_vector_set (wa, j, qtbj);
    }

  /* Eliminate the diagonal matrix d using a Givens rotation */

  for (j = 0; j < n; j++)
    {
      double qtbpj;

      size_t pj = gsl_permutation_get (p, j);

      double diagpj = gsl_vector_get (diag, pj);

      if (diagpj == 0)
	{
	  continue;
	}

      gsl_vector_set (sdiag, j, diagpj);

      for (k = j + 1; k < n; k++)
	{
	  gsl_vector_set (sdiag, k, 0.0);
	}

      /* The transformations to eliminate the row of d modify only a
         single element of qtb beyond the first n, which is initially
         zero */

      qtbpj = 0;

      for (k = j; k < n; k++)
	{
	  /* Determine a Givens rotation which eliminates the
	     appropriate element in the current row of d */

          double sine, cosine;

          double wak = gsl_vector_get (wa, k);
          double rkk = gsl_matrix_get (r, k, k);
	  double sdiagk = gsl_vector_get (sdiag, k);

	  if (sdiagk == 0)
	    {
	      continue;
	    }

	  if (fabs (rkk) < fabs (sdiagk))
	    {
	      double cotangent = rkk / sdiagk;
	      sine = 0.5 / sqrt (0.25 + 0.25 * cotangent * cotangent);
	      cosine = sine * cotangent;
	    }
	  else
	    {
	      double tangent = sdiagk / rkk;
	      cosine = 0.5 / sqrt (0.25 + 0.25 * tangent * tangent);
	      sine = cosine * tangent;
	    }

	  /* Compute the modified diagonal element of r and the
	     modified element of [qtb,0] */

	  {
	    double new_rkk = cosine * rkk + sine * sdiagk;
	    double new_wak = cosine * wak + sine * qtbpj;
	    
            qtbpj = -sine * wak + cosine * qtbpj;

	    gsl_matrix_set(r, k, k, new_rkk);
	    gsl_vector_set(wa, k, new_wak);
          }

	  /* Accumulate the transformation in the row of s */

	  for (i = k + 1; i < n; i++)
	    {
              double rik = gsl_matrix_get (r, i, k);
              double sdiagi = gsl_vector_get (sdiag, i);
              
              double new_rik = cosine * rik + sine * sdiagi;
              double new_sdiagi = -sine * rik + cosine * sdiagi;
              
              gsl_matrix_set(r, i, k, new_rik);
              gsl_vector_set(sdiag, i, new_sdiagi);
	    }
	}

      /* Store the corresponding diagonal element of s and restore the
         corresponding diagonal element of r */

      {
        double rjj = gsl_matrix_get (r, j, j);
        double xj = gsl_vector_get(x, j);
        
        gsl_vector_set (sdiag, j, rjj);
        gsl_matrix_set (r, j, j, xj);
      }

    }

  /* Solve the triangular system for z. If the system is singular then
     obtain a least squares solution */

  nsing = n;

  for (j = 0; j < n; j++)
    {
      double sdiagj = gsl_vector_get (sdiag, j);

      if (sdiagj == 0)
	{
	  nsing = j;
	  break;
	}
    }

  for (j = nsing; j < n; j++)
    {
      gsl_vector_set (wa, j, 0.0);
    }

  for (k = 0; k < nsing; k--)
    {
      size_t j = nsing - k;

      double sum = 0;

      for (i = k; i < nsing; i++)
	{
	  sum += gsl_matrix_get(r, i, j) * gsl_vector_get(wa, i);
	}

      {
        double waj = gsl_vector_get (wa, j);
        double sdiagj = gsl_vector_get (sdiag, j);

        gsl_vector_set (wa, j, (waj - sum) / sdiagj);
      }
    }

  /* Permute the components of z back to the components of x */

  for (j = 0; j < n; i++)
    {
      size_t pj = gsl_permutation_get (p, j);
      double waj = gsl_vector_get (wa, j);

      gsl_vector_set (x, pj, waj);
    }

  return GSL_SUCCESS;
}

/* blas/source_tbmv_c.h
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Gerard Jungman
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * Author:  G. Jungman
 * RCS:     $Id$
 */

{
    int conj = (TransA == CblasConjTrans) ? -1 : 1;
    int Trans = (TransA != CblasConjTrans) ? TransA : CblasTrans;
    int nounit = (Diag == CblasNonUnit);
    size_t i, j;
    size_t ix, jx;


    if ((order == CblasRowMajor && Trans == CblasNoTrans && Uplo == CblasUpper)
	|| (order == CblasColMajor && Trans == CblasTrans && Uplo == CblasLower)) {
	/* form  x := A*x */

	ix = OFFSET(N, incX);
	for (i = 0; i < N; i++) {
	    BASE temp_r = 0.0;
	    BASE temp_i = 0.0;
	    const size_t j_min = i + 1;
	    const size_t j_max = GSL_MIN(N, i + K + 1);
	    size_t jx = OFFSET(N, incX) + incX * j_min;
	    for (j = j_min; j < j_max; j++) {
		const BASE x_real = REAL(X, jx);
		const BASE x_imag = IMAG(X, jx);
		const BASE A_real = REAL(A, lda * (K + i - j) + j);
		const BASE A_imag = conj * IMAG(A, lda * (K + i - j) + j);

		temp_r += A_real * x_real - A_imag * x_imag;
		temp_i += A_real * x_imag + A_imag * x_real;

		jx += incX;
	    }
	    if (nounit) {
		const BASE x_real = REAL(X, ix);
		const BASE x_imag = IMAG(X, ix);
		const BASE A_real = REAL(A, lda * K + i);
		const BASE A_imag = conj * IMAG(A, lda * K + i);

		REAL(X, ix) = temp_r + (A_real * x_real - A_imag * x_imag);
		IMAG(X, ix) = temp_i + (A_real * x_imag + A_imag * x_real);
	    } else {
		REAL(X, ix) += temp_r;
		IMAG(X, ix) += temp_i;
	    }
	    ix += incX;
	}
    } else if ((order == CblasRowMajor && Trans == CblasNoTrans && Uplo == CblasLower)
	       || (order == CblasColMajor && Trans == CblasTrans && Uplo == CblasUpper)) {
	ix = OFFSET(N, incX) + (N - 1) * incX;

	for (i = N; i > 0 && i--;) {	/*  N-1 ... 0 */
	    BASE temp_r = 0.0;
	    BASE temp_i = 0.0;
	    const size_t j_min = (K > i ? 0 : i - K);
	    const size_t j_max = i;
	    jx = OFFSET(N, incX) + j_min * incX;
	    for (j = j_min; j < j_max; j++) {
		const BASE x_real = REAL(X, jx);
		const BASE x_imag = IMAG(X, jx);
		const BASE A_real = REAL(A, lda * (i - j) + j);
		const BASE A_imag = conj * IMAG(A, lda * (i - j) + j);

		temp_r += A_real * x_real - A_imag * x_imag;
		temp_i += A_real * x_imag + A_imag * x_real;

		jx += incX;
	    }
	    if (nounit) {
		const BASE x_real = REAL(X, ix);
		const BASE x_imag = IMAG(X, ix);
		const BASE A_real = REAL(A, lda * 0 + i);
		const BASE A_imag = conj * IMAG(A, lda * 0 + i);

		REAL(X, ix) = temp_r + (A_real * x_real - A_imag * x_imag);
		IMAG(X, ix) = temp_i + (A_real * x_imag + A_imag * x_real);
	    } else {
		REAL(X, ix) += temp_r;
		IMAG(X, ix) += temp_i;
	    }
	    ix -= incX;
	}
    } else if ((order == CblasRowMajor && Trans == CblasTrans && Uplo == CblasUpper)
	       || (order == CblasColMajor && Trans == CblasNoTrans && Uplo == CblasLower)) {
	/* form  x := A'*x */

	ix = OFFSET(N, incX) + (N - 1) * incX;
	for (i = N; i > 0 && i--;) {	/*  N-1 ... 0 */
	    BASE temp_r = 0.0;
	    BASE temp_i = 0.0;
	    const size_t j_min = (K > i ? 0 : i - K);
	    const size_t j_max = i;
	    jx = OFFSET(N, incX) + j_min * incX;
	    for (j = j_min; j < j_max; j++) {
		const BASE x_real = REAL(X, jx);
		const BASE x_imag = IMAG(X, jx);
		const BASE A_real = REAL(A, lda * j + (i - j));
		const BASE A_imag = conj * IMAG(A, lda * j + (i - j));

		temp_r += A_real * x_real - A_imag * x_imag;
		temp_i += A_real * x_imag + A_imag * x_real;

		jx += incX;
	    }
	    if (nounit) {
		const BASE x_real = REAL(X, ix);
		const BASE x_imag = IMAG(X, ix);
		const BASE A_real = REAL(A, lda * i + 0);
		const BASE A_imag = conj * IMAG(A, lda * i + 0);

		REAL(X, ix) = temp_r + (A_real * x_real - A_imag * x_imag);
		IMAG(X, ix) = temp_i + (A_real * x_imag + A_imag * x_real);
	    } else {
		REAL(X, ix) += temp_r;
		IMAG(X, ix) += temp_i;
	    }
	    ix -= incX;
	}
    } else if ((order == CblasRowMajor && Trans == CblasTrans && Uplo == CblasLower)
	       || (order == CblasColMajor && Trans == CblasNoTrans && Uplo == CblasUpper)) {
	ix = OFFSET(N, incX);
	for (i = 0; i < N; i++) {
	    BASE temp_r = 0.0;
	    BASE temp_i = 0.0;
	    const size_t j_min = i + 1;
	    const size_t j_max = GSL_MIN(N, i + K + 1);
	    jx = OFFSET(N, incX) + j_min * incX;
	    for (j = j_min; j < j_max; j++) {
		const BASE x_real = REAL(X, jx);
		const BASE x_imag = IMAG(X, jx);
		const BASE A_real = REAL(A, lda * j + (K - j + i));
		const BASE A_imag = conj * IMAG(A, lda * j + (K - j + i));

		temp_r += A_real * x_real - A_imag * x_imag;
		temp_i += A_real * x_imag + A_imag * x_real;

		jx += incX;
	    }
	    if (nounit) {
		const BASE x_real = REAL(X, ix);
		const BASE x_imag = IMAG(X, ix);
		const BASE A_real = REAL(A, lda * i + K);
		const BASE A_imag = conj * IMAG(A, lda * i + K);

		REAL(X, ix) = temp_r + (A_real * x_real - A_imag * x_imag);
		IMAG(X, ix) = temp_i + (A_real * x_imag + A_imag * x_real);
	    } else {
		REAL(X, ix) += temp_r;
		IMAG(X, ix) += temp_i;
	    }
	    ix += incX;
	}
    } else {
	BLAS_ERROR("unrecognized operation");
    }
}

/*
 * Author:  G. Jungman
 * RCS:     $Id$
 */
/* Raw BLAS interface for row-major matrices.
 * Based on draft BLAST C interface specification  [Jul 7 1998]
 */
#ifndef GSL_BLAS_RAW_H_
#define GSL_BLAS_RAW_H_

#include <gsl_blas_raw_L1.h>
#include <gsl_blas_types.h>


/*
 * ===========================================================================
 * Prototypes for level 2 BLAS
 * ===========================================================================
 */

/* GEMV */
void gsl_blas_raw_sgemv (CBLAS_TRANSPOSE TransA,
                         size_t M, size_t N,
                         float alpha,
                         const float A[], int lda,
                         const float X[], size_t incX,
                         float beta,
                         float Y[], size_t incY);

void gsl_blas_raw_dgemv (CBLAS_TRANSPOSE TransA,
			 size_t M, size_t N,
                         double alpha,
			 const double A[], int lda,
                         const double X[], size_t incX,
			 double beta,
                         double Y[], size_t incY);

void gsl_blas_raw_cgemv (CBLAS_TRANSPOSE TransA,
			 size_t M, size_t N,
                         const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float A, int lda,
                         const gsl_complex_packed_array_float X, size_t incX,
			 const gsl_complex_packed_float beta,
                         gsl_complex_packed_array_float Y, size_t incY);

void gsl_blas_raw_zgemv (CBLAS_TRANSPOSE TransA,
			 size_t M, size_t N,
                         const gsl_complex_packed alpha,
			 const gsl_complex_packed_array A, int lda,
                         const gsl_complex_packed_array X, size_t incX,
			 const gsl_complex_packed beta,
                         gsl_complex_packed_array Y, size_t incY);

/* GBMV */

void gsl_blas_raw_sgbmv (CBLAS_TRANSPOSE TransA,
                         size_t M, size_t N, size_t KL, size_t KU,
			 float alpha,
                         const float A[], int lda,
                         const float X[], size_t incX,
                         float beta,
                         float Y[], size_t incY);

void gsl_blas_raw_dgbmv (CBLAS_TRANSPOSE TransA,
			 size_t M, size_t N, size_t KL, size_t KU,
			 double alpha,
                         const double A[], int lda,
			 const double X[], size_t incX,
			 double beta,
			 double Y[], size_t incY);

void gsl_blas_raw_cgbmv (CBLAS_TRANSPOSE TransA,
			 size_t M, size_t N, size_t KL, size_t KU,
			 const gsl_complex_packed_float alpha,
                         const gsl_complex_packed_array_float A, int lda,
			 const gsl_complex_packed_array_float X, size_t incX,
			 const gsl_complex_packed_float beta,
			 gsl_complex_packed_array_float Y, size_t incY);

void gsl_blas_raw_zgbmv (CBLAS_TRANSPOSE TransA,
			 size_t M, size_t N, size_t KL, size_t KU,
			 const gsl_complex_packed alpha,
                         const gsl_complex_packed_array A, int lda,
			 const gsl_complex_packed_array X, size_t incX,
			 const gsl_complex_packed beta,
			 gsl_complex_packed_array Y, size_t incY);


/* TRMV */

void gsl_blas_raw_strmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
                         const float A[], int lda,
                         float X[], size_t incX);

void gsl_blas_raw_dtrmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const double A[], int lda,
                         double X[], size_t incX);

void gsl_blas_raw_ctrmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const gsl_complex_packed_array_float A, int lda,
                         gsl_complex_packed_array_float X, size_t incX);

void gsl_blas_raw_ztrmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const gsl_complex_packed_array A, int lda,
                         gsl_complex_packed_array X, size_t incX);


/* TBMV */

void gsl_blas_raw_stbmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N, size_t K,
			 const float A[], int lda,
                         float X[], size_t incX);

void gsl_blas_raw_dtbmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N, size_t K,
			 const double A[], int lda,
                         double X[], size_t incX);

void gsl_blas_raw_ctbmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N, size_t K,
			 const gsl_complex_packed_array_float A, int lda,
                         gsl_complex_packed_array_float X, size_t incX);

void gsl_blas_raw_ztbmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N, size_t K,
			 const gsl_complex_packed_array A, int lda,
                         gsl_complex_packed_array X, size_t incX);


/* TPMV */

void gsl_blas_raw_stpmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const float Ap[],
			 float X[], size_t incX);

void gsl_blas_raw_dtpmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const double Ap[],
			 double X[], size_t incX);

void gsl_blas_raw_ctpmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const gsl_complex_packed_array_float Ap,
			 gsl_complex_packed_array_float X, size_t incX);

void gsl_blas_raw_ztpmv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const gsl_complex_packed_array Ap,
			 gsl_complex_packed_array X, size_t incX);

/* TRSV */

void gsl_blas_raw_strsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const float A[], int lda,
			 float X[], size_t incX);

void gsl_blas_raw_dtrsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const double A[], int lda,
			 double X[], size_t incX);

void gsl_blas_raw_ctrsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const gsl_complex_packed_array_float A, int lda,
			 gsl_complex_packed_array_float X, size_t incX);

void gsl_blas_raw_ztrsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const gsl_complex_packed_array A, int lda,
			 gsl_complex_packed_array X, size_t incX);


/* TBSV */

void gsl_blas_raw_stbsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N, size_t K,
			 const float A[], int lda,
                         float X[], size_t incX);

void gsl_blas_raw_dtbsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N, size_t K,
			 const double A[], int lda,
                         double X[], size_t incX);

void gsl_blas_raw_ctbsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N, size_t K,
			 const gsl_complex_packed_array_float A, int lda,
                         gsl_complex_packed_array_float X, size_t incX);

void gsl_blas_raw_ztbsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N, size_t K,
			 const gsl_complex_packed_array A, int lda,
                         gsl_complex_packed_array X, size_t incX);


/* TPSV */

void gsl_blas_raw_stpsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const float Ap[],
			 float X[], size_t incX);

void gsl_blas_raw_dtpsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const double Ap[],
			 double X[], size_t incX);

void gsl_blas_raw_ctpsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const gsl_complex_packed_array_float Ap,
			 gsl_complex_packed_array_float X, size_t incX);

void gsl_blas_raw_ztpsv (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE TransA, CBLAS_DIAG Diag,
                         size_t N,
			 const gsl_complex_packed_array Ap,
			 gsl_complex_packed_array X, size_t incX);


/* SYMV */

void gsl_blas_raw_ssymv (CBLAS_UPLO Uplo,
                         size_t N,
			 float alpha,
			 const float A[], int lda,
			 const float X[], size_t incX,
                         float beta,
			 float Y[], size_t incY);

void gsl_blas_raw_dsymv (CBLAS_UPLO Uplo,
                         size_t N,
			 double alpha,
			 const double A[], int lda,
			 const double X[], size_t incX,
                         double beta,
			 double Y[], size_t incY);


/* SBMV */

void gsl_blas_raw_ssbmv (CBLAS_UPLO Uplo,
                         size_t N, size_t K,
			 float alpha,
			 const float A[], int lda, 
			 const float X[], size_t incX,
                         float beta,
			 float Y[], size_t incY);

void gsl_blas_raw_dsbmv (CBLAS_UPLO Uplo,
                         size_t N, size_t K,
			 double alpha,
			 const double A[], int lda,
			 const double X[], size_t incX,
                         double beta,
			 double Y[], size_t incY);

/* SPMV */

void gsl_blas_raw_sspmv (CBLAS_UPLO Uplo,
                         size_t N,
			 float alpha,
			 const float Ap[],
                         const float X[], size_t incX,
                         float beta,
			 float Y[], size_t incY);

void gsl_blas_raw_dspmv (CBLAS_UPLO Uplo,
                         size_t N,
			 double alpha,
			 const double Ap[],
                         const double X[], size_t incX,
                         double beta,
			 double Y[], size_t incY);

/* GER */

void gsl_blas_raw_sger (size_t M, size_t N,
                        float alpha,
			const float X[], size_t incX,
                        const float Y[], size_t incY,
			float A[], int lda);

void gsl_blas_raw_dger (size_t M, size_t N,
                        double alpha,
			const double X[], size_t incX,
                        const double Y[], size_t incY,
			double A[], int lda);


/* SYR */

void gsl_blas_raw_ssyr (CBLAS_UPLO Uplo,
                        size_t N,
			float alpha,
			const float X[], size_t incX,
			float A[], int lda);

void gsl_blas_raw_dsyr (CBLAS_UPLO Uplo,
                        size_t N,
			double alpha,
			const double X[], size_t incX,
			double A[], int lda);


/* SPR */

void gsl_blas_raw_sspr (CBLAS_UPLO Uplo,
                        size_t N,
			float alpha,
			const float X[], size_t incX,
			float Ap[]);

void gsl_blas_raw_dspr (CBLAS_UPLO Uplo,
                        size_t N,
			double alpha,
			const double X[], size_t incX,
			double Ap[]);


/* SYR2 */

void gsl_blas_raw_ssyr2 (CBLAS_UPLO Uplo,
                         size_t N,
			 float alpha,
			 const float X[], size_t incX, 
			 const float Y[], size_t incY,
			 float A[], int lda);

void gsl_blas_raw_dsyr2 (CBLAS_UPLO Uplo,
                         size_t N,
			 double alpha,
			 const double X[], size_t incX,
			 const double Y[], size_t incY,
			 double A[], int lda);


/* SPR2 */

void gsl_blas_raw_sspr2 (CBLAS_UPLO Uplo,
                         size_t N,
			 float alpha,
			 const float X[], size_t incX,
			 const float Y[], size_t incY,
			 float A[]);

void gsl_blas_raw_dspr2 (CBLAS_UPLO Uplo,
                         size_t N,
			 double alpha,
			 const double X[], size_t incX,
			 const double Y[], size_t incY,
			 double A[]);


/* HEMV */

void gsl_blas_raw_chemv (CBLAS_UPLO Uplo,
                         size_t N,
			 const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float A, int lda,
			 const gsl_complex_packed_array_float X, size_t incX,
                         const gsl_complex_packed_float beta,
			 gsl_complex_packed_array_float Y, size_t incY);

void gsl_blas_raw_zhemv (CBLAS_UPLO Uplo,
                         size_t N,
			 const gsl_complex_packed alpha,
			 const gsl_complex_packed_array A, int lda,
			 const gsl_complex_packed_array X, size_t incX,
                         const gsl_complex_packed beta,
			 gsl_complex_packed_array Y, size_t incY);


/* HBMV */

void gsl_blas_raw_chbmv (CBLAS_UPLO Uplo,
                         size_t N, size_t K,
			 const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float A, int lda,
			 const gsl_complex_packed_array_float X, size_t incX,
                         const gsl_complex_packed_float beta,
			 gsl_complex_packed_array_float Y, size_t incY);

void gsl_blas_raw_zhbmv (CBLAS_UPLO Uplo,
                         size_t N, size_t K,
			 const gsl_complex_packed alpha,
			 const gsl_complex_packed_array A, int lda,
			 const gsl_complex_packed_array X, size_t incX,
                         const gsl_complex_packed beta,
			 gsl_complex_packed_array Y, size_t incY);


/* HPMV */

void gsl_blas_raw_chpmv (CBLAS_UPLO Uplo,
                         size_t N,
			 const gsl_complex_packed_float alpha,
                         const gsl_complex_packed_array_float Ap,
                         const gsl_complex_packed_array_float X, size_t incX,
                         const gsl_complex_packed_float beta,
			 gsl_complex_packed_array_float Y, size_t incY);

void gsl_blas_raw_zhpmv (CBLAS_UPLO Uplo,
                         size_t N,
			 const gsl_complex_packed alpha,
			 const gsl_complex_packed_array Ap,
                         const gsl_complex_packed_array X, size_t incX,
                         const gsl_complex_packed beta,
			 gsl_complex_packed_array Y, size_t incY);


/* GERU */

void gsl_blas_raw_cgeru (size_t M, size_t N,
                         const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float X, size_t incX,
                         const gsl_complex_packed_array_float Y, size_t incY,
			 gsl_complex_packed_array_float A, int lda);

void gsl_blas_raw_zgeru (size_t M, size_t N,
                         const gsl_complex_packed alpha,
			 const gsl_complex_packed_array X, size_t incX,
                         const gsl_complex_packed_array Y, size_t incY,
			 gsl_complex_packed_array A, int lda);


/* GERC */

void gsl_blas_raw_cgerc (size_t M, size_t N,
                         const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float X, size_t incX,
                         const gsl_complex_packed_array_float Y, size_t incY,
			 gsl_complex_packed_array_float A, int lda);

void gsl_blas_raw_zgerc (size_t M, size_t N,
                         const gsl_complex_packed alpha,
			 const gsl_complex_packed_array X, size_t incX,
                         const gsl_complex_packed_array Y, size_t incY,
			 gsl_complex_packed_array A, int lda);

/* HER */

void gsl_blas_raw_cher (CBLAS_UPLO Uplo,
                        size_t N,
			float alpha,
			const gsl_complex_packed_array_float X, size_t incX,
                        gsl_complex_packed_array_float A, int lda);

void gsl_blas_raw_zher (CBLAS_UPLO Uplo,
                        size_t N,
			double alpha,
			const gsl_complex_packed_array X, size_t incX,
                        gsl_complex_packed_array A, int lda);


/* HPR */

void gsl_blas_raw_chpr (CBLAS_UPLO Uplo,
                        size_t N,
			float alpha,
			const gsl_complex_packed_array_float X, size_t incX,
			gsl_complex_packed_array_float A);

void gsl_blas_raw_zhpr (CBLAS_UPLO Uplo,
                        size_t N,
			double alpha,
			const gsl_complex_packed_array X, size_t incX,
			gsl_complex_packed_array A);


/* HER2 */

void gsl_blas_raw_cher2 (CBLAS_UPLO Uplo,
                         size_t N,
                         const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float X, size_t incX,
                         const gsl_complex_packed_array_float Y, size_t incY,
			 gsl_complex_packed_array_float A, int lda);

void gsl_blas_raw_zher2 (CBLAS_UPLO Uplo,
                         size_t N,
                         const gsl_complex_packed alpha,
			 const gsl_complex_packed_array X, size_t incX,
                         const gsl_complex_packed_array Y, size_t incY,
			 gsl_complex_packed_array A, int lda);


/* HPR2 */

void gsl_blas_raw_chpr2 (CBLAS_UPLO Uplo,
                         size_t N,
                         const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float X, size_t incX,
                         const gsl_complex_packed_array_float Y, size_t incY,
			 gsl_complex_packed_array_float Ap);

void gsl_blas_raw_zhpr2 (CBLAS_UPLO Uplo,
                         size_t N,
                         const gsl_complex_packed alpha,
			 const gsl_complex_packed_array X, size_t incX,
                         const gsl_complex_packed_array Y, size_t incY,
			 gsl_complex_packed_array Ap);


/*
 * ===========================================================================
 * Prototypes for level 3 BLAS
 * ===========================================================================
 */

/* GEMM */

void gsl_blas_raw_sgemm (CBLAS_TRANSPOSE TransA,
                         CBLAS_TRANSPOSE TransB,
			 size_t M, size_t N, size_t K,
			 float alpha,
			 const float A[], int lda,
			 const float B[], int ldb,
                         float beta,
			 float C[], int ldc);

void gsl_blas_raw_dgemm (CBLAS_TRANSPOSE TransA,
                         CBLAS_TRANSPOSE TransB,
			 size_t M, size_t N, size_t K,
			 double alpha,
			 const double A[], int lda,
			 const double B[], int ldb,
                         double beta,
			 double C[], int ldc);

void gsl_blas_raw_cgemm (CBLAS_TRANSPOSE TransA,
                         CBLAS_TRANSPOSE TransB,
			 size_t M, size_t N, size_t K,
			 const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float A, int lda, 
			 const gsl_complex_packed_array_float B, int ldb,
                         const gsl_complex_packed_float beta,
			 gsl_complex_packed_array_float C, int ldc);

void gsl_blas_raw_zgemm (CBLAS_TRANSPOSE TransA,
                         CBLAS_TRANSPOSE TransB,
			 size_t M, size_t N, size_t K,
			 const gsl_complex_packed alpha,
			 const gsl_complex_packed_array A, int lda,
			 const gsl_complex_packed_array B, int ldb,
                         const gsl_complex_packed beta,
			 gsl_complex_packed_array C, int ldc);


/* SYMM */

void gsl_blas_raw_ssymm (CBLAS_SIDE Side, CBLAS_UPLO Uplo,
			 size_t M, size_t N,
                         float alpha,
			 const float A[], int lda,
                         const float B[], int ldb,
			 float beta,
                         float C[], int ldc);

void gsl_blas_raw_dsymm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo,
			 size_t M, size_t N,
                         double alpha,
			 const double A[], int lda,
                         const double B[], int ldb,
			 double beta,
                         double C[], int ldc);

void gsl_blas_raw_csymm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo,
			 size_t M, size_t N,
                         const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float A, int lda,
                         const gsl_complex_packed_array_float B, int ldb,
			 const gsl_complex_packed_float beta,
                         gsl_complex_packed_array_float C, int ldc);

void gsl_blas_raw_zsymm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo,
			 size_t M, size_t N,
                         const gsl_complex_packed alpha,
			 const gsl_complex_packed_array A, int lda,
                         const gsl_complex_packed_array B, int ldb,
			 const gsl_complex_packed beta,
                         gsl_complex_packed_array C, int ldc);


/* SYRK */

void gsl_blas_raw_ssyrk (CBLAS_UPLO Uplo, CBLAS_TRANSPOSE Trans,
			 size_t N, size_t K,
                         float alpha,
			 const float A[], int lda,
                         float beta,
			 float C[], int ldc);

void gsl_blas_raw_dsyrk (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE Trans,
			 size_t N, size_t K,
                         double alpha,
			 const double A[], int lda,
                         double beta,
			 double C[], int ldc);

void gsl_blas_raw_csyrk (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE Trans,
			 size_t N, size_t K,
                         const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float A, int lda,
                         const gsl_complex_packed_float beta,
			 gsl_complex_packed_array_float C, int ldc);

void gsl_blas_raw_zsyrk (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE Trans,
			 size_t N, size_t K,
                         const gsl_complex_packed alpha,
			 const gsl_complex_packed_array A, int lda,
                         const gsl_complex_packed beta,
			 gsl_complex_packed_array C, int ldc);


/* SYR2K */

void gsl_blas_raw_ssyr2k (CBLAS_UPLO Uplo, CBLAS_TRANSPOSE Trans,
			  size_t N, size_t K,
                          float alpha,
			  const float A[], int lda,
                          const float B[], int ldb,
			  float beta,
                          float C[], int ldc);

void gsl_blas_raw_dsyr2k (CBLAS_UPLO Uplo,
                          CBLAS_TRANSPOSE Trans,
			  size_t N, size_t K,
                          double alpha,
			  const double A[], int lda,
                          const double B[], int ldb,
			  double beta,
                          double C[], int ldc);

void gsl_blas_raw_csyr2k (CBLAS_UPLO Uplo,
                          CBLAS_TRANSPOSE Trans,
			  size_t N, size_t K,
                          const gsl_complex_packed_float alpha,
			  const gsl_complex_packed_array_float A, int lda,
                          const gsl_complex_packed_array_float B, int ldb,
			  const gsl_complex_packed_float beta,
                          gsl_complex_packed_array_float C, int ldc);

void gsl_blas_raw_zsyr2k (CBLAS_UPLO Uplo,
                          CBLAS_TRANSPOSE Trans,
			  size_t N, size_t K,
                          const gsl_complex_packed alpha,
			  const gsl_complex_packed_array A, int lda,
                          const gsl_complex_packed_array B, int ldb,
			  const gsl_complex_packed beta,
                          gsl_complex_packed_array C, int ldc);


/* TRMM */

void gsl_blas_raw_strmm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo, CBLAS_TRANSPOSE TransA,
                         CBLAS_DIAG Diag,
			 size_t M, size_t N,
                         float alpha,
			 const float A[], int lda,
                         float B[], int ldb);

void gsl_blas_raw_dtrmm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo, CBLAS_TRANSPOSE TransA,
                         CBLAS_DIAG Diag,
			 size_t M, size_t N,
                         double alpha,
			 const double A[], int lda,
                         double B[], int ldb);

void gsl_blas_raw_ctrmm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo, CBLAS_TRANSPOSE TransA,
                         CBLAS_DIAG Diag,
			 size_t M, size_t N,
                         const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float A, int lda,
                         gsl_complex_packed_array_float B, int ldb);

void gsl_blas_raw_ztrmm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo, CBLAS_TRANSPOSE TransA,
                         CBLAS_DIAG Diag,
			 size_t M, size_t N,
                         const gsl_complex_packed alpha,
			 const gsl_complex_packed_array A, int lda,
                         gsl_complex_packed_array B, int ldb);


/* TRSM */

void gsl_blas_raw_strsm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo, CBLAS_TRANSPOSE TransA,
                         CBLAS_DIAG Diag,
			 size_t M, size_t N,
                         float alpha,
			 const float A[], int lda,
                         float B[], int ldb);

void gsl_blas_raw_dtrsm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo, CBLAS_TRANSPOSE TransA,
                         CBLAS_DIAG Diag,
			 size_t M, size_t N,
                         double alpha,
			 const double A[], int lda,
                         double B[], int ldb);

void gsl_blas_raw_ctrsm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo, CBLAS_TRANSPOSE TransA,
                         CBLAS_DIAG Diag,
			 size_t M, size_t N,
                         const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float A, int lda,
                         gsl_complex_packed_array_float B, int ldb);

void gsl_blas_raw_ztrsm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo, CBLAS_TRANSPOSE TransA,
                         CBLAS_DIAG Diag,
			 size_t M, size_t N,
                         const gsl_complex_packed alpha,
			 const gsl_complex_packed_array A, int lda,
                         gsl_complex_packed_array B, int ldb);


/* HEMM */

void gsl_blas_raw_chemm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo,
			 size_t M, size_t N,
                         const gsl_complex_packed_float alpha,
			 const gsl_complex_packed_array_float A, int lda,
                         const gsl_complex_packed_array_float B, int ldb,
			 const gsl_complex_packed_float beta,
                         gsl_complex_packed_array_float C, int ldc);

void gsl_blas_raw_zhemm (CBLAS_SIDE Side,
                         CBLAS_UPLO Uplo,
			 size_t M, size_t N,
                         const gsl_complex_packed alpha,
			 const gsl_complex_packed_array A, int lda,
                         const gsl_complex_packed_array B, int ldb,
			 const gsl_complex_packed beta,
                         gsl_complex_packed_array C, int ldc);


/* HERK */

void gsl_blas_raw_cherk (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE Trans,
			 size_t N, size_t K,
                         float alpha,
			 const gsl_complex_packed_array_float A, int lda,
                         float beta,
			 gsl_complex_packed_array_float C, int ldc);

void gsl_blas_raw_zherk (CBLAS_UPLO Uplo,
                         CBLAS_TRANSPOSE Trans,
			 size_t N, size_t K,
                         double alpha,
			 const gsl_complex_packed_array A, int lda,
                         double beta,
			 gsl_complex_packed_array C, int ldc);


/* HER2K */

void gsl_blas_raw_cher2k (CBLAS_UPLO Uplo,
                          CBLAS_TRANSPOSE Trans,
			  size_t N, size_t K,
                          const gsl_complex_packed_float alpha,
			  const gsl_complex_packed_array_float A, int lda,
                          const gsl_complex_packed_array_float B, int ldb,
			  float beta,
                          gsl_complex_packed_array_float C, int ldc);


void gsl_blas_raw_zher2k (CBLAS_UPLO Uplo,
                          CBLAS_TRANSPOSE Trans,
			  size_t N, size_t K,
                          const gsl_complex_packed alpha,
			  const gsl_complex_packed_array A, int lda,
                          const gsl_complex_packed_array B, int ldb,
			  double beta,
                          gsl_complex_packed_array C, int ldc);


#if defined(HAVE_INLINE) && defined(HAVE_CBLAS)
#include <cblas.h>

/* insert inline cblas implementation of above here */

#endif /* defined(HAVE_INLINE) && defined(HAVE_CBLAS) */


#endif /* !GSL_BLAS_RAW_H_ */

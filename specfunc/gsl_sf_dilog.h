/* specfunc/gsl_sf_dilog.h
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2004 Gerard Jungman
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

/* Author:  G. Jungman */

#ifndef __GSL_SF_DILOG_H__
#define __GSL_SF_DILOG_H__

#include <gsl/gsl_sf_result.h>

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS


/* Real part of DiLogarithm(x), for real argument.
 * In Lewin's notation, this is Li_2(x).
 *
 *   Li_2(x) = - Re[ Integrate[ Log[1-s] / s, {s, 0, x}] ]
 *
 * Note that Im[Li_2(x)] = { 0 for x <= 1, -Pi*log(x) for x > 1 }
 */
int     gsl_sf_dilog_e(const double x, gsl_sf_result * result);
double  gsl_sf_dilog(const double x);


/* DiLogarithm(z), for complex argument z = r Exp[i theta].
 * Computes the principal branch.
 *
 * This function is ok, but the interface is confusing since
 * it makes it appear that the branch structure is resolved.
 * Perhap this interface should be deprecated.
 */
int
gsl_sf_complex_dilog_e(
  const double r,
  double theta,
  gsl_sf_result * result_re,
  gsl_sf_result * result_im
  );


/* DiLogarithm(z), for complex argument z = x + i y.
 * Computes the principal branch.
 */
int
gsl_sf_complex_dilog_xy_e(
  const double x,
  const double y,
  gsl_sf_result * result_re,
  gsl_sf_result * result_im
  );


/* Spence integral; spence(s) := Li_2(1-s)
 *
 * This function has a brnach point at 0; we place the
 * cut on (-infty,0). The branch cut is resolved by
 * specifying s = A exp(i omega). In this way, the
 * implementation computes spence(s) on its full
 * Riemann surface, which is topologically
 * equivalent to the ln(z) Riemann surface.
 */
int
gsl_sf_complex_spence_e(
  const double A,
  const double omega,
  gsl_sf_result * real_sp,
  gsl_sf_result * imag_sp
  );


__END_DECLS

#endif /* __GSL_SF_DILOG_H__ */

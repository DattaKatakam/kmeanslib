#ifndef KMEANSLIB_GLOBAL_H
#define KMEANSLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KMEANSLIB_LIBRARY)
#  define KMEANSLIB_EXPORT Q_DECL_EXPORT
#else
#  define KMEANSLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // KMEANSLIB_GLOBAL_H

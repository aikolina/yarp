/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_os_API_H
#define YARP_os_API_H

#include <yarp/conf/api.h>
#ifndef YARP_os_API
#    ifdef YARP_os_EXPORTS
#        define YARP_os_API YARP_EXPORT
#        define YARP_os_EXTERN YARP_EXPORT_EXTERN
#    else
#        define YARP_os_API YARP_IMPORT
#        define YARP_os_EXTERN YARP_IMPORT_EXTERN
#    endif
#    define YARP_os_DEPRECATED_API YARP_DEPRECATED_API
#    define YARP_os_DEPRECATED_API_MSG(X) YARP_DEPRECATED_API_MSG(X)
#endif

#ifndef YARP_init_API
#    ifdef YARP_init_EXPORTS
#        define YARP_init_API YARP_EXPORT
#        define YARP_init_EXTERN YARP_EXPORT_EXTERN
#    else
#        define YARP_init_API YARP_IMPORT
#        define YARP_init_EXTERN YARP_IMPORT_EXTERN
#    endif
#    define YARP_init_DEPRECATED_API YARP_DEPRECATED_API
#    define YARP_init_DEPRECATED_API_MSG(X) YARP_DEPRECATED_API_MSG(X)
#endif

#ifndef YARP_os_impl_API
// FIXME YARP should not export symbols from os/impl.
//       Unfortunately at the moment, methods from impl are used in other
//       internal libraries, forcing us to export them in the library
#    ifdef YARP_FILTER_impl
#        define YARP_os_impl_API
#    else
#        define YARP_os_impl_API YARP_os_API
#    endif
#endif

#ifndef YARP_NO_DEPRECATED // since YARP 3.3
#    if defined(USING_DEPRECATED_UPPERCASE_YARP_OS_TARGET)
#        include <yarp/conf/system.h>
         YARP_COMPILER_WARNING("The YARP::YARP_OS target is deprecated. Use YARP::YARP_os instead")
#    endif
#endif // YARP_NO_DEPRECATED

#endif // YARP_os_API_H

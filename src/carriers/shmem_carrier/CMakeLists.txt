# Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

yarp_prepare_plugin(shmem
                    CATEGORY carrier
                    TYPE ShmemCarrier
                    INCLUDE ShmemCarrier.h
                    EXTRA_CONFIG CODE=\\\"YA\\\"\ 0xE3\ 0x1E\ 0\ 0\ \\\"RP\\\"
                    DEPENDS "YARP_HAS_ACE"
                    DEFAULT ON)

if(NOT SKIP_shmem)
  yarp_add_plugin(yarp_shmem)

  target_sources(yarp_shmem PRIVATE ShmemCarrier.cpp
                                    ShmemCarrier.h
                                    ShmemHybridStream.cpp
                                    ShmemHybridStream.h
                                    ShmemInputStream.cpp
                                    ShmemInputStream.h
                                    ShmemOutputStream.cpp
                                    ShmemOutputStream.h
                                    ShmemTypes.h)

  target_link_libraries(yarp_shmem PRIVATE YARP::YARP_os)
  list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS YARP_os)

  target_compile_definitions(yarp_shmem PRIVATE YARP_HAS_ACE)
  target_link_libraries(yarp_shmem PRIVATE ACE::ACE)
  list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS ACE)

  yarp_install(TARGETS yarp_shmem
               EXPORT YARP_${YARP_PLUGIN_MASTER}
               COMPONENT ${YARP_PLUGIN_MASTER}
               LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
               ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR}
               YARP_INI DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR})

  set(YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS ${YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS} PARENT_SCOPE)

  set_property(TARGET yarp_shmem PROPERTY FOLDER "Plugins/Carrier")
endif()
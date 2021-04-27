//
// Created by diegoubuntu on 26/4/21.
//

#ifndef PROYECTO_I_DII_C__LOGGERI_H
#define PROYECTO_I_DII_C__LOGGERI_H


#define BOOST_LOG_DYN_LINK

#include <boost/log/trivial.hpp>
#include <boost/log/sources/global_logger_storage.hpp>

#define LOGFILE "loggerI.log"

#define SEVERITY_THRESHOLD logging::trivial::warning

BOOST_LOG_GLOBAL_LOGGER(logger, boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level>)

#define LOG(severity) BOOST_LOG_SEV(logger::get(),boost::log::trivial::severity)

#define LOG_TRACE   LOG(trace)
#define LOG_DEBUG   LOG(debug)
#define LOG_INFO    LOG(info)
#define LOG_WARNING LOG(warning)
#define LOG_ERROR   LOG(error)
#define LOG_FATAL   LOG(fatal)



#endif //PROYECTO_I_DII_C__LOGGERI_H

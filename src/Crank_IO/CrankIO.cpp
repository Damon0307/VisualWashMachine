/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-12-06 14:30:56
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-14 13:17:42
 * @FilePath: \VirtualMachine\src\Crank_IO\CrankIO.cpp
 * @Description: 基础IO层实现文件
 */

#include <iostream>
#include <thread>
#include <functional>

extern "C"
{
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "include/gre/greio.h"
 
}
 
#include <windows.h>
#include "CrankIO.h"

//#define COMPILE_IN_VS 1

#define RECV_BUFFER_MAX_SIZE 2048

#define HELLO_EVENT "Tool4VM"
#define HELLO_FMT "4s1 id 1s0 name"
typedef struct
{
  int32_t id;
  char name[1];
} hello_event_t;

//#define _NO_CRT_STDIO_INLINE

using namespace std;

void CrankIO::InitIOChannel()
{
#ifdef COMPILE_IN_VS
  gre_io_t *send_handle;
  gre_io_serialized_data_t *nbuffer = NULL;

#endif

#ifdef COMPILE_IN_VS
  send_handle = gre_io_open(target_io_name.c_str(),GRE_IO_TYPE_WRONLY);
 
  if(NULL!= send_handle)
  {
    std::cout<<" send_handle open success"<< std::endl;
  }

 hello_event_t *test_msg;
 test_msg = (hello_event_t *)malloc(sizeof(*test_msg)+strlen("hello"));
 test_msg->id=20;
 strcpy(test_msg->name,"hello");

 nbuffer = gre_io_serialize(nbuffer,NULL,HELLO_EVENT,HELLO_FMT,test_msg,sizeof(*test_msg));

 int ret =  gre_io_send(send_handle,nbuffer);

 if(ret < 0)
 {
     std::cout<<"fucking send err"<<std::endl;
 }
 
 gre_io_free_buffer(nbuffer);
 gre_io_close(send_handle);
#endif
}

bool CrankIO::SendMSG(const char *data, const char *fmt, int len, const char *target)
{
}

//接收通道中的消息
void CrankIO::RecvMSG()
{
#ifdef COMPILE_IN_VS
  gre_io_t *handle;
  gre_io_serialized_data_t *nbuffer = NULL;
  char *event_addr;
  char *event_name;
  char *event_format;
  void *event_data;
  int ret;
  int nbytes;

   printf("Opening a channel for receive\n");
   // handle = gre_io_open(m_io_name.c_str(),GRE_IO_TYPE_RDONLY);
  if (handle == NULL) {
  		fprintf(stderr, "Can't open receive channel\n");
  	   exit(-1);
  	}

  nbuffer = gre_io_size_buffer(NULL, RECV_BUFFER_MAX_SIZE);

  while (1)
  {
    this_thread::sleep_for(chrono::milliseconds(10));
   // ret = gre_io_receive(handle,&nbuffer);

    if (ret < 0) 
    {
			 continue;
		}else
    {
      event_name = NULL;
		  nbytes = gre_io_unserialize(nbuffer, &event_addr, &event_name, &event_format, &event_data);
        for(auto i : m_ob_map)
        {
          ob_func recv_func=i.second;
          recv_func(event_name,event_data,event_format);
        }
    }
  }
  #endif
}

void CrankIO::AddObserver(ob_func observer_func, int observer_id)
{
   m_ob_map.insert(make_pair(observer_id,observer_func));
}
 
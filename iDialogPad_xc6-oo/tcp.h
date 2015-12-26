/*
 *  tcp.h
 *  AccelerometerGraph
 *
 *  Created by Gerhard Mutz1 on 28.08.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

struct xin_addr {
  union {
    struct {
      u_char s_b1,s_b2,s_b3,s_b4;
    } S_un_b;
    struct {
      u_short s_w1,s_w2;
    } S_un_w;
    u_long S_addr;
  } S_un;
}; 


struct xsockaddr_in {
        short   sin_family;
        u_short sin_port;
        struct  xin_addr sin_addr;
        char    sin_zero[8];
};

#if 0
struct ysockaddr_in {
	unsigned char	sin_len;
	sa_family_t	sin_family;
	in_port_t	sin_port;
	struct	xin_addr sin_addr;
	char		sin_zero[8];		/* XXX bwg2001-004 */
};
#endif

long tcp_listen(char *addr,long port);
long tcp_readx(unsigned char *buff,long num);
long tcp_write(unsigned char *buff, long num);
long tcp_getlen(char *str);
long tcp_read(unsigned char *buff,long num);
long udp_getlen(char *str);
long udp_open(char *addr,long port);
long udp_read(char *str,short slen);
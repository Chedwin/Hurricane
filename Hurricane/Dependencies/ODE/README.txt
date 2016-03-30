============================================
DLLs and header files for the ODE Physics Library
============================================

In this zip file you will find two dll files called 'libode.dll' and 'libopcode.dll', you will also find two folders called 'ode' and 'drawstuff'. 
Copy the liblibode.a file to the lib folder of your compiler and copy the two folders to the include folder of your compiler. 
I have only made one change to the config.h file which is located in the ode folder; this was due to a conflicting definition of int32 in winsock2.h. 

The source code for ODE was released under the GNU Lesser General Public License http://www.opensource.org/licenses/lgpl-license.html 
or the BSD-style license http://opende.sourceforge.net/ode-license.html and 
you can download the complete source code and binaries for ODE at the official ode webite at http://www.q12.org. 

Thanks go to Russell Smith for making ODE an open source project.
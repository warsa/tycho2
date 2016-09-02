/*
    Comm.hh
*/

/*
Copyright (c) 2016, Los Alamos National Security, LLC
All rights reserved.

Copyright 2016. Los Alamos National Security, LLC. This software was produced 
under U.S. Government contract DE-AC52-06NA25396 for Los Alamos National 
Laboratory (LANL), which is operated by Los Alamos National Security, LLC for 
the U.S. Department of Energy. The U.S. Government has rights to use, 
reproduce, and distribute this software.  NEITHER THE GOVERNMENT NOR LOS 
ALAMOS NATIONAL SECURITY, LLC MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR 
ASSUMES ANY LIABILITY FOR THE USE OF THIS SOFTWARE.  If software is modified 
to produce derivative works, such modified software should be clearly marked, 
so as not to confuse it with the version available from LANL.

Additionally, redistribution and use in source and binary forms, with or 
without modification, are permitted provided that the following conditions 
are met:
1.      Redistributions of source code must retain the above copyright notice, 
        this list of conditions and the following disclaimer.
2.      Redistributions in binary form must reproduce the above copyright 
        notice, this list of conditions and the following disclaimer in the 
        documentation and/or other materials provided with the distribution.
3.      Neither the name of Los Alamos National Security, LLC, Los Alamos 
        National Laboratory, LANL, the U.S. Government, nor the names of its 
        contributors may be used to endorse or promote products derived from 
        this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY LOS ALAMOS NATIONAL SECURITY, LLC AND 
CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT 
NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL LOS ALAMOS NATIONAL 
SECURITY, LLC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __COMM_HH__
#define __COMM_HH__

#include "Typedef.hh"
#include <mpi.h>
#include <vector>
#include <string>

namespace Comm
{

int rank();
int rank(MPI_Comm comm);
int numRanks();

void gsum(double &x);
void gsum(int &x);
void gsum(UINT &x);
void gmax(double &x);
void gmax(double &x, MPI_Comm comm);
void gmax(int &x);
void gmax(UINT &x);
UINT exscan(UINT x);

void sendInt(int i, int destination);
void sendUInt(UINT i, int destination);
void sendIntVector(const std::vector<int> &buffer, int destination);
void sendUIntVector(const std::vector<UINT> &buffer, int destination);
void iSendIntVector(const std::vector<int> &buffer, int destination, int tag, 
                    MPI_Request &request);
void iSendUIntVector(const std::vector<UINT> &buffer, int destination, int tag, 
                     MPI_Request &request);
void iSendDoubleVector(const std::vector<double> &buffer, int destination, int tag, 
                       MPI_Request &request);

void recvInt(int &i, int destination);
void recvUInt(UINT &i, int destination);
void recvIntVector(std::vector<int> &buffer, int destination);
void recvUIntVector(std::vector<UINT> &buffer, int destination);
void recvIntVector(std::vector<int> &buffer, int destination, int tag);
void recvUIntVector(std::vector<UINT> &buffer, int destination, int tag);
void recvDoubleVector(std::vector<double> &buffer, int destination, int tag);

void barrier();

void openFileForRead(const std::string &filename, MPI_File &file);
void openFileForWrite(const std::string &filename, MPI_File &file);
void closeFile(MPI_File &file);
void seek(const MPI_File &file, uint64_t position);
void readUint64(const MPI_File &file, uint64_t &data);
void readUint64(const MPI_File &file, uint64_t *data, int numData);
void readChars(const MPI_File &file, char *data, int numData);
void writeDoublesAt(const MPI_File &file, UINT offset, double *data, UINT numData);

} // End namespace

#endif

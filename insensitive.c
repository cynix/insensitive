#include <CoreServices/CoreServices.h>
#include "dyld-interposing.h"

static OSStatus _FSGetVolumeParms(FSVolumeRefNum volume, GetVolParmsInfoBuffer* buffer, ByteCount bufferSize)
{
	OSStatus status = FSGetVolumeParms(volume, buffer, bufferSize);
	buffer->vMExtendedAttributes &= ~(1 << bIsCaseSensitive);
	return status;
}

DYLD_INTERPOSE(_FSGetVolumeParms, FSGetVolumeParms);

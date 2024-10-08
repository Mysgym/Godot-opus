#ifndef GODOPUSENCODER_H
#define GODOPUSENCODER_H

#include "opusConfig.h"

#include <godot_cpp/classes/node.hpp>
#include <opus.h>

namespace godot {
	
	class GdOpusEncoder : public Node {
		GDCLASS(GdOpusEncoder, Node);

		protected:
			OpusEncoder *opusEncoder;
			
			static void _bind_methods();

		public:
			GdOpusEncoder();
			~GdOpusEncoder();
			PackedByteArray encode(PackedVector2Array samples);
			//utility function for resampler
			int get_resampler_input_size();
	};

}

#endif

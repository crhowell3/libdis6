#include "libsersi/simulation_management/CreateEntityPdu.h"

#include <cstddef>

namespace dis {
CreateEntityPdu::CreateEntityPdu() : request_id_(0) { SetPduType(11); }

uint32_t CreateEntityPdu::GetRequestId() const { return request_id_; }

void CreateEntityPdu::SetRequestId(uint32_t value) { request_id_ = value; }

void CreateEntityPdu::Marshal(DataStream& data_stream) const {
  SimulationManagementFamilyPdu::Marshal(data_stream);
  data_stream << request_id_;
}

void CreateEntityPdu::Unmarshal(DataStream& data_stream) {
  SimulationManagementFamilyPdu::Unmarshal(data_stream);
  data_stream >> request_id_;
}

bool CreateEntityPdu::operator==(const CreateEntityPdu& rhs) const {
  bool ivars_equal = true;

  ivars_equal = SimulationManagementFamilyPdu::operator==(rhs);

  if (!(request_id_ == rhs.request_id_)) {
    ivars_equal = false;
  }

  return ivars_equal;
}

std::size_t CreateEntityPdu::GetMarshalledSize() const {
  std::size_t marshal_size =
      SimulationManagementFamilyPdu::GetMarshalledSize() + sizeof(request_id_);
  return marshal_size;
}

}  // namespace dis

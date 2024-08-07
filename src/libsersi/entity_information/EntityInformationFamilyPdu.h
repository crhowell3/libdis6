#pragma once

#include <cstddef>

#include "libsersi/common/Pdu.h"
#include "libsersi/utils/DataStream.h"

namespace dis {
// Section 5.3.3. Common superclass for EntityState, Collision,
// collision-elastic, and entity state update PDUs. This should be abstract.
// COMPLETE

class EntityInformationFamilyPdu : public Pdu {
 public:
  EntityInformationFamilyPdu();
  ~EntityInformationFamilyPdu() override = default;

  void Marshal(DataStream& data_stream) const override;
  void Unmarshal(DataStream& data_stream) override;

  [[nodiscard]] std::size_t GetMarshalledSize() const override;

  bool operator==(const EntityInformationFamilyPdu& rhs) const;
};
}  // namespace dis

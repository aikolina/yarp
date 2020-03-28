/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

// Autogenerated by Thrift Compiler (0.12.0-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <yarp/test/PointD.h>

namespace yarp {
namespace test {

// Default constructor
PointD::PointD() :
        WirePortable(),
        x(0),
        y(0),
        z(0)
{
}

// Constructor with field values
PointD::PointD(const std::int32_t x,
               const std::int32_t y,
               const std::int32_t z) :
        WirePortable(),
        x(x),
        y(y),
        z(z)
{
}

// Read structure on a Wire
bool PointD::read(yarp::os::idl::WireReader& reader)
{
    if (!read_x(reader)) {
        return false;
    }
    if (!read_y(reader)) {
        return false;
    }
    if (!read_z(reader)) {
        return false;
    }
    return !reader.isError();
}

// Read structure on a Connection
bool PointD::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(3)) {
        return false;
    }
    return read(reader);
}

// Write structure on a Wire
bool PointD::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_x(writer)) {
        return false;
    }
    if (!write_y(writer)) {
        return false;
    }
    if (!write_z(writer)) {
        return false;
    }
    return !writer.isError();
}

// Write structure on a Connection
bool PointD::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(3)) {
        return false;
    }
    return write(writer);
}

// Convert to a printable string
std::string PointD::toString() const
{
    yarp::os::Bottle b;
    b.read(*this);
    return b.toString();
}

// Editor: default constructor
PointD::Editor::Editor()
{
    group = 0;
    obj_owned = true;
    obj = new PointD;
    dirty_flags(false);
    yarp().setOwner(*this);
}

// Editor: constructor with base class
PointD::Editor::Editor(PointD& obj)
{
    group = 0;
    obj_owned = false;
    edit(obj, false);
    yarp().setOwner(*this);
}

// Editor: destructor
PointD::Editor::~Editor()
{
    if (obj_owned) {
        delete obj;
    }
}

// Editor: edit
bool PointD::Editor::edit(PointD& obj, bool dirty)
{
    if (obj_owned) {
        delete this->obj;
    }
    this->obj = &obj;
    obj_owned = false;
    dirty_flags(dirty);
    return true;
}

// Editor: validity check
bool PointD::Editor::isValid() const
{
    return obj != nullptr;
}

// Editor: state
PointD& PointD::Editor::state()
{
    return *obj;
}

// Editor: grouping begin
void PointD::Editor::start_editing()
{
    group++;
}

// Editor: grouping end
void PointD::Editor::stop_editing()
{
    group--;
    if (group == 0 && is_dirty) {
        communicate();
    }
}
// Editor: x setter
void PointD::Editor::set_x(const std::int32_t x)
{
    will_set_x();
    obj->x = x;
    mark_dirty_x();
    communicate();
    did_set_x();
}

// Editor: x getter
std::int32_t PointD::Editor::get_x() const
{
    return obj->x;
}

// Editor: x will_set
bool PointD::Editor::will_set_x()
{
    return true;
}

// Editor: x did_set
bool PointD::Editor::did_set_x()
{
    return true;
}

// Editor: y setter
void PointD::Editor::set_y(const std::int32_t y)
{
    will_set_y();
    obj->y = y;
    mark_dirty_y();
    communicate();
    did_set_y();
}

// Editor: y getter
std::int32_t PointD::Editor::get_y() const
{
    return obj->y;
}

// Editor: y will_set
bool PointD::Editor::will_set_y()
{
    return true;
}

// Editor: y did_set
bool PointD::Editor::did_set_y()
{
    return true;
}

// Editor: z setter
void PointD::Editor::set_z(const std::int32_t z)
{
    will_set_z();
    obj->z = z;
    mark_dirty_z();
    communicate();
    did_set_z();
}

// Editor: z getter
std::int32_t PointD::Editor::get_z() const
{
    return obj->z;
}

// Editor: z will_set
bool PointD::Editor::will_set_z()
{
    return true;
}

// Editor: z did_set
bool PointD::Editor::did_set_z()
{
    return true;
}

// Editor: clean
void PointD::Editor::clean()
{
    dirty_flags(false);
}

// Editor: read
bool PointD::Editor::read(yarp::os::ConnectionReader& connection)
{
    if (!isValid()) {
        return false;
    }
    yarp::os::idl::WireReader reader(connection);
    reader.expectAccept();
    if (!reader.readListHeader()) {
        return false;
    }
    int len = reader.getLength();
    if (len == 0) {
        yarp::os::idl::WireWriter writer(reader);
        if (writer.isNull()) {
            return true;
        }
        if (!writer.writeListHeader(1)) {
            return false;
        }
        writer.writeString("send: 'help' or 'patch (param1 val1) (param2 val2)'");
        return true;
    }
    std::string tag;
    if (!reader.readString(tag)) {
        return false;
    }
    if (tag == "help") {
        yarp::os::idl::WireWriter writer(reader);
        if (writer.isNull()) {
            return true;
        }
        if (!writer.writeListHeader(2)) {
            return false;
        }
        if (!writer.writeTag("many", 1, 0)) {
            return false;
        }
        if (reader.getLength() > 0) {
            std::string field;
            if (!reader.readString(field)) {
                return false;
            }
            if (field == "x") {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeString("std::int32_t x")) {
                    return false;
                }
            }
            if (field == "y") {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeString("std::int32_t y")) {
                    return false;
                }
            }
            if (field == "z") {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeString("std::int32_t z")) {
                    return false;
                }
            }
        }
        if (!writer.writeListHeader(4)) {
            return false;
        }
        writer.writeString("*** Available fields:");
        writer.writeString("x");
        writer.writeString("y");
        writer.writeString("z");
        return true;
    }
    bool nested = true;
    bool have_act = false;
    if (tag != "patch") {
        if (((len - 1) % 2) != 0) {
            return false;
        }
        len = 1 + ((len - 1) / 2);
        nested = false;
        have_act = true;
    }
    for (int i = 1; i < len; ++i) {
        if (nested && !reader.readListHeader(3)) {
            return false;
        }
        std::string act;
        std::string key;
        if (have_act) {
            act = tag;
        } else if (!reader.readString(act)) {
            return false;
        }
        if (!reader.readString(key)) {
            return false;
        }
        if (key == "x") {
            will_set_x();
            if (!obj->nested_read_x(reader)) {
                return false;
            }
            did_set_x();
        } else if (key == "y") {
            will_set_y();
            if (!obj->nested_read_y(reader)) {
                return false;
            }
            did_set_y();
        } else if (key == "z") {
            will_set_z();
            if (!obj->nested_read_z(reader)) {
                return false;
            }
            did_set_z();
        } else {
            // would be useful to have a fallback here
        }
    }
    reader.accept();
    yarp::os::idl::WireWriter writer(reader);
    if (writer.isNull()) {
        return true;
    }
    writer.writeListHeader(1);
    writer.writeVocab(yarp::os::createVocab('o', 'k'));
    return true;
}

// Editor: write
bool PointD::Editor::write(yarp::os::ConnectionWriter& connection) const
{
    if (!isValid()) {
        return false;
    }
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(dirty_count + 1)) {
        return false;
    }
    if (!writer.writeString("patch")) {
        return false;
    }
    if (is_dirty_x) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("x")) {
            return false;
        }
        if (!obj->nested_write_x(writer)) {
            return false;
        }
    }
    if (is_dirty_y) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("y")) {
            return false;
        }
        if (!obj->nested_write_y(writer)) {
            return false;
        }
    }
    if (is_dirty_z) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("z")) {
            return false;
        }
        if (!obj->nested_write_z(writer)) {
            return false;
        }
    }
    return !writer.isError();
}

// Editor: send if possible
void PointD::Editor::communicate()
{
    if (group != 0) {
        return;
    }
    if (yarp().canWrite()) {
        yarp().write(*this);
        clean();
    }
}

// Editor: mark dirty overall
void PointD::Editor::mark_dirty()
{
    is_dirty = true;
}

// Editor: x mark_dirty
void PointD::Editor::mark_dirty_x()
{
    if (is_dirty_x) {
        return;
    }
    dirty_count++;
    is_dirty_x = true;
    mark_dirty();
}

// Editor: y mark_dirty
void PointD::Editor::mark_dirty_y()
{
    if (is_dirty_y) {
        return;
    }
    dirty_count++;
    is_dirty_y = true;
    mark_dirty();
}

// Editor: z mark_dirty
void PointD::Editor::mark_dirty_z()
{
    if (is_dirty_z) {
        return;
    }
    dirty_count++;
    is_dirty_z = true;
    mark_dirty();
}

// Editor: dirty_flags
void PointD::Editor::dirty_flags(bool flag)
{
    is_dirty = flag;
    is_dirty_x = flag;
    is_dirty_y = flag;
    is_dirty_z = flag;
    dirty_count = flag ? 3 : 0;
}

// read x field
bool PointD::read_x(yarp::os::idl::WireReader& reader)
{
    if (!reader.readI32(x)) {
        reader.fail();
        return false;
    }
    return true;
}

// write x field
bool PointD::write_x(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeI32(x)) {
        return false;
    }
    return true;
}

// read (nested) x field
bool PointD::nested_read_x(yarp::os::idl::WireReader& reader)
{
    if (!reader.readI32(x)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) x field
bool PointD::nested_write_x(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeI32(x)) {
        return false;
    }
    return true;
}

// read y field
bool PointD::read_y(yarp::os::idl::WireReader& reader)
{
    if (!reader.readI32(y)) {
        reader.fail();
        return false;
    }
    return true;
}

// write y field
bool PointD::write_y(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeI32(y)) {
        return false;
    }
    return true;
}

// read (nested) y field
bool PointD::nested_read_y(yarp::os::idl::WireReader& reader)
{
    if (!reader.readI32(y)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) y field
bool PointD::nested_write_y(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeI32(y)) {
        return false;
    }
    return true;
}

// read z field
bool PointD::read_z(yarp::os::idl::WireReader& reader)
{
    if (!reader.readI32(z)) {
        reader.fail();
        return false;
    }
    return true;
}

// write z field
bool PointD::write_z(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeI32(z)) {
        return false;
    }
    return true;
}

// read (nested) z field
bool PointD::nested_read_z(yarp::os::idl::WireReader& reader)
{
    if (!reader.readI32(z)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) z field
bool PointD::nested_write_z(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeI32(z)) {
        return false;
    }
    return true;
}

} // namespace yarp
} // namespace test
/*
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is Subler.
 *
 * The Initial Developer of the Original Code is Damiano Galassi.
 * Portions created by Damiano Galassi are Copyright (C) 2021.
 * All Rights Reserved.
 *
 * Contributor(s):
 *      Damiano Galassi, damiog@gmail.com
 */

#include "src/impl.h"

namespace mp4v2 {
namespace impl {

///////////////////////////////////////////////////////////////////////////////


MP4AlacAtom::MP4AlacAtom(MP4File &file)
        : MP4Atom(file, "alac")
{
    AddVersionAndFlags(); /* 0, 1 */
}

void MP4AlacAtom::Generate()
{
    AddProperty( /* 2 */
                new MP4BytesProperty(*this,"magicCookie", 48));

    MP4Atom::Generate();
}

void MP4AlacAtom::Read()
{
    AddProperty( /* 2 */
                new MP4BytesProperty(*this,"magicCookie", m_size - 4));

    MP4Atom::Read();
}

///////////////////////////////////////////////////////////////////////////////

}
} // namespace mp4v2::impl

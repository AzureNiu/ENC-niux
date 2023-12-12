## 文件说明

`network/model/buffer.h/cc` 仿照HPCC增加函数GetBuffer

`network/model/net-device.h/cc` 仿照HPCC增加虚函数SwitchSend

`network/model/node.h/cc` 仿照HPCC增加虚函数SwitchReceiveFromDevice, SwitchNotifyDequeue

`network/model/packet.h/cc` 仿照HPCC增加函数Create, GetBuffer

`network/utils/broadcom-egress-queue.h/cc` 根据ns3.37的语言风格修改为类模板

`network/utils/custom-header-niux.h/cc` 根据实际需求，对解析包头部分代码进行重构

`network/utils/int-header-niux.h/cc` 根据实际需求，重新设计自定义INT头（后期可重命名）

`point-to-point/model/enc-header.h/cc` 基于qbb进行修改，修改为适合我们使用的ACK包读取和赋值形式

`point-to-point/model/enc-channel.h/cc` 基于qbb进行修改，去除RDMA部分，仅保留可供中间路由器使用的内容

`point-to-point/model/enc-net-device.h/cc` 基于qbb进行修改，去除RDMA部分，仅保留可供中间路由器使用的内容

`point-to-point/model/point-to-point-net-device.h/cc` 仿照HPCC增加函数GetRate

`point-to-point/model/ppp-header.h/cc` 仿照HPCC增加函数GetSerializedSize, GetStaticSize, Serialize, Deserialize

`point-to-point/model/switch-mmu.h/cc` 基于HPCC版本进行修改，去除RDMA部分，仅保留可供中间路由器使用的内容

`point-to-point/model/switch-node.h/cc` 基于HPCC版本进行修改，去除RDMA部分，仅保留可供中间路由器使用的内容。采用静态路由表的形式确定路径选择，并对所有经过的TCP包进行包头修改，记录所需信息


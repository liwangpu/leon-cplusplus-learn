# MoreJee API Client库使用方式

## 1. 关于API的基础知识

此处不做介绍,详情查看文档

## 2. Client库的结构

### 2.1. 基础结构和明明空间

根据API微服务的划分，导出头文件和cpp已经将各个服务的请求类切割到相关文件夹，使用两级命名空间将服务隔离，一级命名空间都为MoreJeeAPI，二级命名空间和各个文件夹名称相同。
例如在include文件夹下有一个MoreJee文件夹，代表有一个MoreJee的微服务，里面包含所有MoreJee业务的API服务类。

```
以MoreJee文件夹下的产品服务类ProductServe.h为例，要使用该服务类，命名空间为MoreJeeAPI::MoreJee
```

### 2.2. 服务类参数结构

每个服务类有自己的参数结构，参数信息和服务类在一个头文件。MoreJee API使用CQRS架构模式，所以在服务类里面有几种类型的参数：Query参数，Command参数，DTO参数。Query和Command参数是请求信息，DTO参数是返回信息（Query参数和Command参数不同点在于Query是查询类参数，不会改变服务器资源信息；而Command参数是命令类型参数，是请求更改服务器资源信息）。DTO参数是服务类返回信息参数。

```
以MoreJee文件夹下的产品服务类ProductServe.h为例，产品服务类有如下的方法：Query,GetById,Create,Update,Delete..

Query是分页查询产品信息
GetById是获取单个产品信息
Create是创建一个产品信息
Update是修改产品信息

Query，GetById是查询资源的方法，不会改变资源的状态，所以它的参数基本都是Query，QueryDTO系列
Create，Update是改变资源的方法，会修改资源的状态，所以它的参数基本都是Command,CommandDTO系列

```
﻿using System;
using REC.Tools;

namespace REC.Intrinsic.Types.API
{
    static class CompilerType
    {
        static readonly HandleCache<ICompiler> Instances = new HandleCache<ICompiler>();

        public static ITypeModuleIntrinsic Get()
        {
            return new TypeModuleIntrinsic
            {
                Name = "Compiler",
                TypeSize = 8,
                NetType = typeof(ICompiler),
                ToNetType = ToNetType,
                FromNetType = FromNetType,
                IsCompileTimeOnly = true,
            };
        }

        static void FromNetType(dynamic net, byte[] bytes)
        {
            var value = (ICompiler)net;
            var handle = Instances.GetHandle(value);
            Instances.AddRef(handle);
            BitConverter.GetBytes(handle).CopyTo(bytes, index: 0);
        }

        static object ToNetType(byte[] arg)
        {
            var handle = BitConverter.ToInt32(arg, startIndex: 0);
            return Instances.GetValue(handle);
        }
    }
}
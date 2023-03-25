// by https://github.com/anysoft
var packageName = common.getlpparam().packageName;
// package 
if (packageName == 'com.dragon.read') {
    // get classloader
    common.hookAllMethods('android.app.ActivityThread', 'performLaunchActivity', null, function (param) {
        var mInitialApplication = common.getObjectField(param.thisObject, 'mInitialApplication');
        var classLoader = common.callMethod(mInitialApplication, 'getClassLoader');

        gsonClass = common.findClass('com.google.gson.Gson', classLoader);
        gson = gsonClass.newInstance();
        // hook method 
        
        // 打印堆栈
        // common.hookAllMethods('com.dragon.read.util.ToastUtils', 'showCommonToast',function (param) {
        //     if(param.args[0].getClass().toString() == 'class java.lang.String'){
        //         throwable = new java.lang.Throwable();
        //         stackTraceElements = throwable.getStackTrace();
        //         if (stackTraceElements != null) {
        //             stackTraceElements.forEach(element => {
        //                 common.log(gson.toJson(element));
        //             });
 
        //         }
        //     }

        // }, null);

        common.hookAllConstructors('com.dragon.read.user.h', function (param) {
            // common.log(param.args.length)
            if (param.args.length == 2) {
                // common.log(gson.toJson(param.args[0]));
                common.log(gson.toJson(param.args[1]));
                var infoResponse = param.args[1];
                // define var 
                var currentTimeMillis = java.lang.System.currentTimeMillis();
                var expireDay = 365;
                var leftTime = 1000 + 60 * 60 * 24 * expireDay;
                var freeAdLeft = leftTime;
                var expireTime = java.lang.Long.valueOf(currentTimeMillis / 1000 + leftTime);
                // common.log('init expireTime = ' + expireTime);
                var data = infoResponse.data;
                data.freeAd = true;
                data.freeAdDay = java.lang.Integer.valueOf(expireDay)
                data.freeAdExpire = expireTime;
                data.freeAdLeft = java.lang.Long.valueOf(freeAdLeft);
                data.hasMedal = true;
                data.vipLastExpiredTime = java.lang.Long.valueOf(1654752180).toString();

                var vipInfo = data.vipInfo;
                vipInfo.continueMonth = true;
                vipInfo.continueMonthBuy = true;
                vipInfo.expireTime = expireTime.toString();
                vipInfo.isVip = '1';
                vipInfo.leftTime = java.lang.Long.valueOf(leftTime).toString();
                data.vipInfo = vipInfo;

                // privilege 
                privilege = data.privilege
                userPrivilegeClass = common.findClass('com.dragon.read.rpc.model.UserPrivilege',classLoader);
                function addPrivilege(id,name,extra){
                    p = userPrivilegeClass.newInstance();
                    p.id = id
                    p.name = name
                    p.isForever = '1'
                    p.extra = extra
                    p.startTime = '1586012290';
                    p.expireTime = '4078997890';
                    p.leftTime = '2492985600';
                    p.downloadBookIds = null;
                    return p;
                }
                if(privilege.size() > 0){
                    common.log('original privilege: ' + gson.toJson(privilege));
                    privilege.clear();
                }
                privilege.add(addPrivilege('6703327493505422087','TTS权益','{\"from\":4}'));
                privilege.add(addPrivilege('7025948416286921516','TTS权益','{\"from\":4}'));
                privilege.add(addPrivilege('6703327536606089992','激励数据权益','{\"from\":1}'));
                privilege.add(addPrivilege('6766572795204735752','批量下载','{\"from\":1}'));
                privilege.add(addPrivilege('6703327401314620167','免广告','{\"from\":1}'));
                privilege.add(addPrivilege('7077535443348116268','所有场景免广告','{\"from\":1}'));
                privilege.add(addPrivilege('6703327578779816712','离线阅读','{\"from\":1}'));
                privilege.add(addPrivilege('6836977122288866051','','{\"from\":1}')); // 自动阅读
                data.privilege = privilege

                infoResponse.data = data;
                //set result into param.args
                param.args[1] = infoResponse;

                // common.log(data.getClass().toString())

                
                // common.log(gson.toJson(param.args[0]));
                // common.log(gson.toJson(param.args[1]));
                // common.log(gson.toJson(gson.fromJson(gson.toJson(param.args[1]),infoResponse.getClass())))
            } else {
                common.log('length not equal 2')
            }
        }, null);
    });
}